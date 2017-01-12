/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:09:39 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:14:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static uint32_t	g_reg_is[256] = {
	['.'] = IS_PRINT,
	['a'] = IS_ALPHA,
	['l'] = IS_LOWER,
	['u'] = IS_UPPER,
	['d'] = IS_DIGIT,
	['n'] = IS_ALNUM,
	['s'] = IS_SPACE,
	['w'] = IS_WORD,
};

#define REG_IS(C)		(((C) > 0) ? g_reg_is[(C) & 0xFF] : 0)

static void		reg_is(uint32_t is, t_reg **reg)
{
	t_reg_set		*r;
	uint32_t		i;

	r = NEW(t_reg_set);
	memset(r, 0, sizeof(t_reg_set));
	r->reg.type = REG_T_SET;
	i = 0;
	while (i < 128)
	{
		if (IS(i, is))
			BITARRAY_SET(r->set, i);
		i++;
	}
	*reg = V(r);
}

bool			parse_reg_block_is(t_sub sub, t_reg **reg)
{
	uint32_t		i;
	uint32_t			is;

	i = 0;
	is = 0;
	while (i < sub.length)
	{
		is |= REG_IS(sub.str[i]);
		i++;
	}
	reg_is(is, reg);
	return (true);
}

uint32_t		parse_reg_is(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	reg_is(REG_IS(p->str[offset]), reg);
	return (offset + 1);
}

static void		bitset_range(t_reg_set *r, uint32_t a, uint32_t b)
{
	if (a < b)
		ft_bitset(r->set, a, b - a + 1);
	else
		ft_bitset(r->set, b, a - b + 1);
}

uint32_t		parse_reg_set(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg_set			*r;
	uint32_t			i;
	char				c;

	i = ++offset;
	while (offset < p->len && p->str[offset] != ']')
		offset++;
	if (offset >= p->len)
		return (REG_ERROR(p, "Unclosed set", i));
	r = NEW(t_reg_set);
	memset(r, 0, sizeof(t_reg_set));
	while (i < offset)
	{
		c = p->str[i++];
		if ((i + 2) <= offset && p->str[i] == '-')
		{
			bitset_range(r, c, p->str[++i]);
			i++;
		}
		else
			BITARRAY_SET(r->set, c);
	}
	r->reg.type = REG_T_SET;
	*reg = V(r);
	return (offset + 1);
}
