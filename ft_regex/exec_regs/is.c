/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 23:25:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

#define REG_IS(F)		(IS(F(m->str[offset]), reg->is))

uint32_t		exec_reg_is(t_rmatch *m, t_reg_is const *reg, uint32_t offset)
{
	uint32_t const	min = reg->reg.min + offset;
	uint32_t const	max = MIN(reg->reg.max + offset, m->len);
	uint32_t const	start = offset;
	uint32_t		tmp;

	if (min >= m->len)
		return (REG_FAIL);
	while (offset < reg->reg.max)
	{
		if (offset >= reg->reg.min && reg->reg.flags & REG_F_MINIMAL
			&& (tmp = exec_reg_next(m, V(reg), start, offset)) != REG_FAIL)
			return (tmp);
		if (!(BOOL_OF(REG_IS()
				|| (reg->reg.flags & REG_F_ICASE && REG_IS(LOWER)))
			^ BOOL_OF(reg->reg.flags & REG_F_NOT)))
			break ;
		offset++;
	}
	if (!(reg->reg.flags & REG_F_MINIMAL))
		while (offset > reg->reg.min)
			if ((tmp = exec_reg_next(m, V(reg), start, offset--)) != REG_FAIL)
				return (tmp);
	return (REG_FAIL);
}
