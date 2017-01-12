/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenmap_builder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:55:22 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:13:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenmap_builder.h"

static bool		dupplicated_token(t_tokenmap_builder *b, t_sub str)
{
	t_tokenmap_builder_t const	*t;

	t = VECTOR_IT(b->tokens);
	while (VECTOR_NEXT(b->tokens, t))
		if (SUB_EQU(SUB(b->str_buff.str + t->str.x, t->str.y), str))
			return (true);
	return (false);
}

bool			ft_tokenmap_builder_add(t_tokenmap_builder *b,
					t_sub pattern, void const *data)
{
	t_tokenmap_builder_t	t;

	if (dupplicated_token(b, pattern))
		return (false);
	t.str = VEC2U(b->str_buff.length, pattern.length);
	ft_dstradd(&b->str_buff, pattern);
	t.data = data;
	if (pattern.length == 0)
	{
		if (b->def != NULL)
			return (false);
		b->def = data;
	}
	else
		ft_vpush(&b->tokens, &t, 1);
	return (true);
}

static void		build_token_match(t_tokenmap_builder const *b,
					t_tokenmap_builder_t const *t, t_vector *dst)
{
	t_sub const			pattern = SUB(b->str_buff.str + t->str.x, t->str.y);
	uint32_t			i;
	t_tokenmap_match	match;

	i = 0;
	while (i < pattern.length)
	{
		if (pattern.str[i] == '\0')
		{
			match.type = (pattern.str[++i] == '+' && (++i, true)) ?
				TOKENMAP_MATCH_SET_REPEAT : TOKENMAP_MATCH_SET;
			memset(match.set, 0, sizeof(match.set));
			while (pattern.str[i] != '\0' && i < pattern.length)
			{
				BITARRAY_SET(match.set, pattern.str[i]);
				if ((i + 2) < pattern.length && pattern.str[i + 1] == '-'
					&& pattern.str[i] <= pattern.str[i + 2])
				{
					ft_bitset(match.set, pattern.str[i],
						pattern.str[i + 2] - pattern.str[i]);
					i += 2;
				}
				i++;
			}
			i++;
		}
		else
		{
			match.type = TOKENMAP_MATCH_STR;
			match.str.length = 0;
			while (i < pattern.length
				&& pattern.str[i] != '\0'
				&& match.str.length < sizeof(match.str.c))
				match.str.c[match.str.length++] = pattern.str[i++];
		}
		ft_vpush(dst, &match, 1);
	}
}

static void		build_tokens(t_tokenmap_builder const *b, t_tokenmap_t **dst)
{
	uint32_t					i;
	t_tokenmap_builder_t const	*t;
	t_vector					match;

	match = VECTOR(t_tokenmap_match);
	i = 0;
	while (i < b->tokens.length)
	{
		match.length = 0;
		t = VECTOR_GET(b->tokens, i);
		build_token_match(b, t, &match);
		dst[i] = MALLOC(sizeof(t_tokenmap_match)
				+ S(t_tokenmap_match, match.length));
		*dst[i] = (t_tokenmap_t){
			ENDOF(dst[i]),
			match.length,
			t->data
		};
		memcpy(dst[i]->match, match.data, S(t_tokenmap_match, match.length));
		i++;
	}
	ft_vclear(&match);
}

static void		build_idx(t_tokenmap_builder const *b,
					t_tokenmap_t const *const *tokens_t,
					t_tokenmap_idx *idx_dst, t_vector *tokens_dst)
{
	uint32_t					i;
	uint32_t					j;
	t_tokenmap_builder_t const	*t;

	i = 0;
	while (i < 256)
	{
		idx_dst[i].idx = tokens_dst->length;
		j = 0;
		while (j < b->tokens.length)
		{
			t = VECTOR_GET(b->tokens, j);
			ASSERT(t->str.y != 0, "empty string");
			if ((tokens_t[j]->match->type == TOKENMAP_MATCH_STR)
				? (tokens_t[j]->match->str.c[0] == (char)i)
				: (BITARRAY_GET(tokens_t[j]->match->set, i)))
				ft_vpush(tokens_dst, &tokens_t[j], 1);

			j++;
		}
		idx_dst[i].len = tokens_dst->length - idx_dst[i].idx;
		i++;
	}
}

t_tokenmap		*ft_tokenmap_builder_done(t_tokenmap_builder *b)
{
	t_tokenmap			*tokenmap;
	t_tokenmap_idx		idx[256];
	t_vector			tokens_t_idx;
	t_tokenmap_t		*tokens_t[b->tokens.length];

	tokens_t_idx = VECTOR(t_tokenmap_t const*);
	build_tokens(b, tokens_t);
	build_idx(b, V(tokens_t), idx, &tokens_t_idx);
	tokenmap = MALLOC(sizeof(t_tokenmap)
			+ S(t_tokenmap_t const*, tokens_t_idx.length));
	memcpy(tokenmap->idx, idx, sizeof(idx));
	tokenmap->t = ENDOF(tokenmap);
	tokenmap->def = b->def;
	memcpy(ENDOF(tokenmap), tokens_t_idx.data,
		S(t_tokenmap_t const*, tokens_t_idx.length));
	ft_vclear(&tokens_t_idx);
	ft_dstrclear(&b->str_buff);
	ft_vclear(&b->tokens);
	return (tokenmap);
}
