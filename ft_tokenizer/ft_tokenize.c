/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:15:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/18 11:15:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"

static bool		match_match(t_tokenizer *t,
					t_tokenmap_match const *m, uint32_t *offset)
{
	uint32_t		i;

	if (m->type == TOKENMAP_MATCH_STR)
	{
		i = 0;
		while (i < m->str.length)
		{
			if (!BUFF_IN_CHECK(t->buff, *offset)
					|| m->str.c[i] != BUFF_IN_GETC(t->buff, *offset))
				return (false);
			i++;
			(*offset)++;
		}
	}
	else
	{
		if (!BUFF_IN_CHECK(t->buff, *offset)
				|| !BITARRAY_GET(m->set, BUFF_IN_GETC(t->buff, *offset)))
			return (false);
		(*offset)++;
		if (m->type == TOKENMAP_MATCH_SET_REPEAT)
			while (BUFF_IN_CHECK(t->buff, *offset)
					&& BITARRAY_GET(m->set, BUFF_IN_GETC(t->buff, *offset)))
				(*offset)++;
	}
	return (true);
}

static uint32_t	tokenizer_match(t_tokenizer *t,
					t_tokenmap_t const *token, uint32_t end)
{
	uint32_t		match_i;
	uint32_t		i;

	match_i = 0;
	i = end;
	while (true)
	{
		if (!match_match(t, &token->match[match_i], &i))
			break ;
		if (++match_i >= token->match_count)
			return (i - end);
	}
	return (0);
}

static bool		tokenizer_get_token(t_tokenizer *t, uint32_t *end)
{
	uint32_t		i;
	uint32_t		len;
	uint32_t		tmp;
	uint32_t		token_len;

	i = t->token_map->idx[(uint8_t)BUFF_IN_GETC(t->buff, *end)].idx;
	len = i + t->token_map->idx[(uint8_t)BUFF_IN_GETC(t->buff, *end)].len;
	token_len = 0;
	while (i < len)
	{
		tmp = tokenizer_match(t, t->token_map->t[i], *end);
		if (tmp > token_len)
		{
			t->token = t->token_map->t[i]->data;
			token_len = tmp;
		}
		i++;
	}
	if (token_len == 0)
		return (false);
	t->token_str = SUB(t->buff.buff + t->buff.i + *end, token_len);
	return (true);
}

static bool		tokenize(t_tokenizer *t, uint32_t *end)
{
	uint32_t const	start = *end; // = 0

	t->token_str.length = 0;
	while (true)
	{
		if (!BUFF_IN_CHECK(t->buff, *end))
		{
			if (start >= *end)
				t->eof = true;
			break ;
		}
		if (t->token_map->idx[(uint8_t)BUFF_IN_GETC(t->buff, *end)].len != 0
				&& tokenizer_get_token(t, end))
		{
			if (start < *end)
				break ;
			*end += t->token_str.length;
			return (true);
		}
		if (t->token_map->def == NULL)
			break ;
		(*end)++;
	}
	t->token_str = SUB(t->buff.buff + t->buff.i + start, *end - start);
	t->token = t->token_map->def;
	return (start < *end);
}

bool			ft_tokenize(t_tokenizer *t)
{
	uint32_t		end;
	bool			r;

	end = 0;
	r = tokenize(t, &end);
	t->buff.i += end;
	return (r);
}

bool			ft_tokenize_ahead(t_tokenizer *t, t_sub *str, void const **data)
{
	t_vec2u				curr_token_str;
	void *const *const	curr_token_data = t->token;
	uint32_t			end;
	bool				r;

	curr_token_str.y = t->token_str.length;
	end = curr_token_str.y;
	t->buff.i -= curr_token_str.y;
	curr_token_str.x = t->token_str.str - t->buff.buff - t->buff.i;
	r = tokenize(t, &end);
	if (str != NULL)
		*str = t->token_str;
	if (data != NULL)
		*data = t->token;
	t->token_str.str = t->buff.buff + curr_token_str.x + t->buff.i;
	t->token_str.length = curr_token_str.y;
	t->token = curr_token_data;
	t->buff.i += curr_token_str.y;
	return (r);
}

void			ft_tokenizer_reset(t_tokenizer *t)
{
	ft_buff_in_clear(&t->buff);
	t->token_map = NULL;
	t->token_str = SUB0();
	t->token = NULL;
	t->eof = false;
}
