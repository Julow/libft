/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:15:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/08/15 15:25:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"

static bool		find_max_t(t_tokenizer *t,
					t_token_map_t const *token, t_sub const *match)
{
	uint32_t const	to = t->end + token->str.length;
	uint32_t		i;

	if (token->str.length <= t->token.length)
		return (true);
	i = t->end;
	while (i < to)
	{
		if (i >= t->buff.length)
		{
			if (!IN_REFRESH(t->in))
				return (true);
			DSTR_APPEND(&t->buff, IN_READ(t->in));
		}
		if (t->buff.str[i] != token->str.str[i - t->end])
			return (true);
		i++;
	}
	t->token.length = token->str.length;
	t->token_data = ENDOF(token);
	return (true);
	(void)match;
}

static bool		is_token(t_tokenizer *t, uint32_t start)
{
	t_sub const		match = SUB(t->buff.str + t->end, 1);

	t->token.length = 0;
	ft_bst_getall(&t->token_map->tokens, &match, &find_max_t, t);
	if (t->token.length > 0)
	{
		if (t->end > start)
		{
			t->token.length = 0;
			return (true);
		}
		t->token.str = t->buff.str + t->end;
		t->end += t->token.length;
		return (true);
	}
	return (false);
}

static bool		tokenize(t_tokenizer *t)
{
	uint32_t const	start = t->end;

	t->token.length = 0;
	while (true)
	{
		if (t->end >= t->buff.length)
		{
			if (!IN_REFRESH(t->in))
				break ;
			DSTR_APPEND(&t->buff, IN_READ(t->in));
		}
		if (BITARRAY_GET(t->token_map->token_starts,
				(uint8_t)t->buff.str[t->end]) && is_token(t, start))
			break ;
		t->end++;
	}
	if (t->token.length > 0)
		return (true);
	t->token = SUB(t->buff.str + start, t->end - start);
	t->token_data = t->token_map->def;
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
			VEC2U(t->token.str - t->buff.str, t->token.length);
	void *const *const	curr_token_data = t->token_data;
	bool const			r = tokenize(t);

	if (str != NULL)
		*str = t->token;
	if (data != NULL)
		*data = t->token_data;
	t->end = curr_token_str.x + curr_token_str.y;
	t->token = SUB(t->buff.str + curr_token_str.x, curr_token_str.y);
	t->token_data = curr_token_data;
	return (r);
}

void			ft_tokenizer_reset(t_tokenizer *t, bool destroy)
{
	if (destroy)
		ft_dstrclear(&t->buff);
	t->buff.length = 0;
	t->end = 0;
	t->token = SUB0();
	t->token_data = NULL;
}
