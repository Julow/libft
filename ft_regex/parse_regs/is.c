/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:10:44 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 20:29:46 by juloo            ###   ########.fr       */
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

uint32_t		parse_reg_is(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg_is		*r;
	t_is			is;

	is = REG_IS(p->str[offset]);
	if (p->str[offset] == '<')
	{
		while (++offset < p->len && p->str[offset] != '>')
			is |= REG_IS(p->str[offset]);
		if (offset >= p->len)
			return (REG_FAIL);
	}
	r = MAL1(t_reg_is);
	r->reg.type = REG_T_IS;
	r->is = is;
	*reg = V(r);
	return (offset + 1);
}
