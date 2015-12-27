/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:10:44 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 20:34:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static uint32_t	g_reg_is[(uint8_t)-1] = {
	['.'] = IS_PRINT,
	['a'] = IS_ALPHA,
	['l'] = IS_LOWER,
	['u'] = IS_UPPER,
	['d'] = IS_DIGIT,
	['n'] = IS_ALNUM,
	['s'] = IS_SPACE,
	['w'] = IS_WORD,
};

uint32_t		parse_reg_is(t_sub pattern, uint32_t offset, t_reg **reg)
{
	t_reg_is		*r;
	t_is			is;

	is = g_reg_is[pattern.str[offset]];
	if (pattern.str[offset] == '<')
	{
		while (++offset < pattern.length && pattern.str[++offset] != '>')
			is |= g_reg_is[pattern.str[offset]];
		if (offset >= pattern.length)
			return (REG_FAIL);
	}
	r = MAL1(t_reg_is);
	r->reg.type = REG_T_IS;
	r->is = is;
	*reg = V(r);
	return (offset + 1);
}
