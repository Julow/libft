/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:15:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/10 22:40:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"

static bool		find_max_t(t_token_def const *def, t_sub const *match,
					t_tokenizer *t)
{
	uint32_t const	to = t->end + def->sub.length;
	uint32_t		i;

	if (def->sub.length <= t->token.length)
		return (true);
	i = t->end;
	while (i < to)
	{
		if (i >= t->buff.length)
		{
			if (!IN_REFRESH(t->in))
				return (true);
			DSTR_APPEND(&t->buff, IN_READ(t->in));
			t->char_count++;
		}
		if (t->buff.str[i] != def->sub.str[i - t->end])
			return (true);
		i++;
	}
	t->token.length = def->sub.length;
	t->token_data = def->data;
	return (true);
	(void)match;
}

static uint32_t	clean_buff(t_tokenizer *t)
{
	if (t->end >= t->buff.length)
	{
		t->buff.length = 0;
		t->end = 0;
	}
	return (t->end);
}

bool			ft_tokenize(t_tokenizer *t)
{
	uint32_t const	start = clean_buff(t);
	t_sub			match;

	while (true)
	{
		if (t->end >= t->buff.length)
		{
			if (!IN_REFRESH(t->in))
				break ;
			DSTR_APPEND(&t->buff, IN_READ(t->in));
			t->char_count++;
		}
		if (BITARRAY_GET(t->token_map->token_starts, t->buff.str[t->end]))
		{
			match = SUB(t->buff.str + t->end, 1);
			t->token.length = 0;
			ft_bst_getall(&t->token_map->tokens, &match, &find_max_t, t);
			if (t->token.length > 0)
			{
				if (t->end > start)
					break ;
				t->token.str = t->buff.str + t->end;
				t->end += t->token.length;
				return (true);
			}
		}
		t->end++;
	}
	t->token = SUB(t->buff.str + start, t->end - start);
	t->token_data = NULL;
	if (start >= t->end)
		return (false);
	return (true);
}

void			ft_tokenizer_reset(t_tokenizer *t, bool destroy)
{
	if (destroy)
		ft_dstrclear(&t->buff);
	t->buff.length = 0;
	t->end = 0;
	t->char_count = 0;
	t->token = SUB0();
	t->token_data = NULL;
}
