/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:15:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/08/28 00:18:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"

static t_tokenmap_state const	*next_state(t_tokenmap_state const *state, char c)
{
	t_vec2u					i;
	uint32_t				tmp;

	i = VEC2U(0, state->count);
	while (i.x < i.y)
	{
		tmp = (i.y - i.x) / 2 + i.x;
		if (state->c[tmp] == c)
			return (state->states[tmp]);
		i = (state->c[tmp] > c) ? VEC2U(i.x, tmp) : VEC2U(tmp + 1, i.y);
	}
	return (NULL);
}

static bool		get_token(t_tokenizer *t)
{
	t_tokenmap_state const	*state;
	uint32_t				offset;
	uint32_t				token_len;

	state = t->token_map->s;
	offset = t->end;
	token_len = 0;
	while (true)
	{
		if (state->data != NULL)
		{
			token_len = offset - t->end;
			t->token = state->data;
		}
		if (offset >= t->buff.length)
		{
			if (!IN_REFRESH(t->in))
				break ;
			DSTR_APPEND(&t->buff, IN_READ(t->in));
		}
		if ((state = next_state(state, t->buff.str[offset])) == NULL)
			break ;
		offset++;
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
		if (t->end >= t->buff.length)
		{
			if (!IN_REFRESH(t->in))
				break ;
			DSTR_APPEND(&t->buff, IN_READ(t->in));
		}
		if (BITARRAY_GET(t->token_map->first, (uint8_t)t->buff.str[t->end])
				&& get_token(t))
		{
			if (start < t->end)
				break ;
			t->end += t->token_str.length;
			return (true);
		}
		t->end++;
	}
	t->token_str = SUB(t->buff.str + start, t->end - start);
	t->token = t->token_map->s->data;
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
}
