/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:09:39 by juloo             #+#    #+#             */
/*   Updated: 2016/01/19 16:10:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static t_is		g_reg_is[((uint8_t)-1)>>1] = {
	['.'] = IS_PRINT,
	['a'] = IS_ALPHA,
	['l'] = IS_LOWER,
	['u'] = IS_UPPER,
	['d'] = IS_DIGIT,
	['n'] = IS_ALNUM,
	['s'] = IS_SPACE,
	['w'] = IS_WORD,
};

#define REG_IS(C)		(((C) > 0) ? g_reg_is[(uint8_t)(C)] : 0)

bool			parse_reg_block_is(t_sub sub, t_reg **reg)
{
	t_reg_set		*r;
	uint32_t		i;
	t_is			is;

	i = 0;
	is = 0;
	while (i < sub.length)
	{
		is |= REG_IS(sub.str[i]);
		i++;
	}
	r = NEW(t_reg_set);
	ft_bzero(r, sizeof(t_reg_set));
	r->reg.type = REG_T_SET;
	r->is = is;
	*reg = V(r);
	return (true);
}

uint32_t		parse_reg_is(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg_set		*r;
	t_is			is;

	is = REG_IS(p->str[offset]);
	r = NEW(t_reg_set);
	ft_bzero(r, sizeof(t_reg_set));
	r->reg.type = REG_T_SET;
	r->is = is;
	*reg = V(r);
	return (offset + 1);
}

uint32_t		parse_reg_set(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg_set			*r;
	uint32_t			i;
	char				c;
	char				end;

	i = ++offset;
	while (offset < p->len && p->str[offset] != ']')
		offset++;
	if (offset >= p->len)
		return (REG_ERROR(p, "Unclosed set", i));
	r = NEW(t_reg_set);
	ft_bzero(r, sizeof(t_reg_set));
	while (i < offset)
	{
		c = p->str[i++];
		if ((i + 2) <= offset && p->str[i] == '-')
		{
			if (c < (end = p->str[++i]))
				ft_bitset(r->set, c, end - c + 1);
			else
				ft_bitset(r->set, end, c - end + 1);
			i++;
		}
		else
			BITARRAY_SET(r->set, c);
	}
	r->reg.type = REG_T_SET;
	*reg = V(r);
	return (offset + 1);
}
