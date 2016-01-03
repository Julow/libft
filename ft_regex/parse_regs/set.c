/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:09:39 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 15:09:36 by juloo            ###   ########.fr       */
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
	r = MAL1(t_reg_set);
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

uint32_t		parse_reg_is(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg_set		*r;
	t_is			is;

	is = REG_IS(p->str[offset]);
	if (p->str[offset] == '<')
	{
		while (++offset < p->len && p->str[offset] != '>')
			is |= REG_IS(p->str[offset]);
		if (offset >= p->len)
			return (REG_ERROR(p, "Unclosed is block", offset));
	}
	r = MAL1(t_reg_set);
	ft_bzero(r, sizeof(t_reg_set));
	r->reg.type = REG_T_SET;
	r->is = is;
	*reg = V(r);
	return (offset + 1);
}
