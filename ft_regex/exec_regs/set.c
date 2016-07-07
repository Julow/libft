/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/07/07 13:12:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

#define REG_SET(F)	(BITARRAY_GET(reg->set, (uint8_t)F(m->str.str[offset])))

uint32_t		exec_reg_set(t_rmatch *m, t_reg_set const *reg, uint32_t offset)
{
	uint32_t const	min = reg->reg.min + offset;
	uint32_t const	max = MIN(reg->reg.max + offset, m->str.length);
	uint32_t const	start = offset;
	uint32_t		tmp;

	if (min > m->str.length)
		return (REG_FAIL);
	while (true)
	{
		if (offset >= min && reg->reg.flags & REG_F_MINIMAL
			&& (tmp = exec_reg_next(m, V(reg), start, offset)) != REG_FAIL)
			return (tmp);
		if (offset >= max)
			break ;
		if (!(BOOL_OF(REG_SET()
				|| (reg->reg.flags & REG_F_ICASE && REG_SET(LOWER)))
			^ BOOL_OF(reg->reg.flags & REG_F_NOT)))
			break ;
		offset++;
	}
	if (!(reg->reg.flags & REG_F_MINIMAL))
		while (offset >= min && offset <= max)
			if ((tmp = exec_reg_next(m, V(reg), start, offset--)) != REG_FAIL)
				return (tmp);
	return (REG_FAIL);
}
