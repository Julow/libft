/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:15:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/05 17:32:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"

#define T_READ(T, I)	((I) < (T)->buff.length || _T_READ(T))

#define _T_READ(T)		(IN_REFRESH((T)->in) ? (__T_READ((T)), true) : ((T)->eof = true, false))
#define __T_READ(T)		DSTR_APPEND(&T->buff, T->in->buff[T->in->buff_i++])

static bool		match_match(t_tokenizer *t,
					t_tokenmap_match const *m, uint32_t *offset)
{
	uint32_t		i;

	if (m->type == TOKENMAP_MATCH_STR)
	{
		i = 0;
		while (i < m->str.length)
		{
			if (!T_READ(t, *offset) || m->str.c[i] != t->buff.str[*offset])
				return (false);
			i++;
			(*offset)++;
		}
	}
	else
	{
		if (!T_READ(t, *offset) || !BITARRAY_GET(m->set, t->buff.str[*offset]))
			return (false);
		(*offset)++;
		if (m->type == TOKENMAP_MATCH_SET_REPEAT)
			while (T_READ(t, *offset) && BITARRAY_GET(m->set, t->buff.str[*offset]))
				(*offset)++;
	}
	return (true);
}

static uint32_t	tokenizer_match(t_tokenizer *t, t_tokenmap_t const *token)
{
	uint32_t		match_i;
	uint32_t		i;

	match_i = 0;
	i = t->end;
	while (true)
	{
		if (!match_match(t, &token->match[match_i], &i))
			break ;
		if (++match_i >= token->match_count)
			return (i - t->end);
	}
	return (0);
}

static bool		tokenizer_get_token(t_tokenizer *t)
{
	uint32_t		i;
	uint32_t		end;
	uint32_t		tmp;
	uint32_t		token_len;

	i = t->token_map->idx[(uint8_t)t->buff.str[t->end]].idx;
	end = i + t->token_map->idx[(uint8_t)t->buff.str[t->end]].len;
	token_len = 0;
	while (i < end)
	{
		tmp = tokenizer_match(t, t->token_map->t[i]);
		if (tmp > token_len)
		{
			t->token = t->token_map->t[i]->data;
			token_len = tmp;
		}
		i++;
	}
	if (token_len == 0)
		return (false);
	t->token_str = SUB(t->buff.str + t->end, token_len);
	return (true);
}

static bool		tokenize(t_tokenizer *t)
{
	uint32_t const	start = t->end;

	t->token_str.length = 0;
	while (true)
	{
		if (!T_READ(t, t->end))
			break ;
		if (t->token_map->idx[(uint8_t)t->buff.str[t->end]].len != 0
				&& tokenizer_get_token(t))
		{
			if (start < t->end)
				break ;
			t->end += t->token_str.length;
			return (true);
		}
		if (t->token_map->def == NULL)
			break ;
		t->end++;
	}
	t->token_str = SUB(t->buff.str + start, t->end - start);
	t->token = t->token_map->def;
	return (start < t->end);
}

bool			ft_tokenize(t_tokenizer *t)
{
	if (t->end >= t->buff.length)
	{
		t->buff.length = 0;
		t->end = 0;
	}
	return (tokenize(t));
}

bool			ft_tokenize_ahead(t_tokenizer *t, t_sub *str, void const **data)
{
	t_vec2u const		curr_token_str =
			VEC2U(t->token_str.str - t->buff.str, t->token_str.length);
	void *const *const	curr_token_data = t->token;
	bool const			r = tokenize(t);

	if (str != NULL)
		*str = t->token_str;
	if (data != NULL)
		*data = t->token;
	t->end = curr_token_str.x + curr_token_str.y;
	t->token_str = SUB(t->buff.str + curr_token_str.x, curr_token_str.y);
	t->token = curr_token_data;
	return (r);
}

void			ft_tokenizer_reset(t_tokenizer *t, bool destroy)
{
	if (destroy)
		ft_dstrclear(&t->buff);
	t->buff.length = 0;
	t->end = 0;
	t->token_str = SUB0();
	t->token = NULL;
	t->eof = false;
}

void			ft_tokenizer_inject(t_tokenizer *t, t_sub s)
{
	t_vec2u const		curr_token_str =
			VEC2U(t->token_str.str - t->buff.str, t->token_str.length);

	ft_memcpy(ft_dstrspan(&t->buff, t->end, t->end, s.length), s.str, s.length);
	t->token_str = SUB(t->buff.str + curr_token_str.x, curr_token_str.y);
}
