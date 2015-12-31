/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:27:12 by juloo             #+#    #+#             */
/*   Updated: 2016/01/01 00:45:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static uint32_t	(*g_exec_regs[__REG_T_COUNT])(t_rmatch*, t_reg const*, uint32_t) = {
	[REG_T_STR] = &exec_reg_str,
	[REG_T_IS] = &exec_reg_is,
	[REG_T_SET] = &exec_reg_set,
	[REG_T_GROUP] = &exec_reg_group,
	[REG_T_EOL] = &exec_reg_eol,
	[REG_T_WBOUND] = &exec_reg_wbound,
};

// TODO: non-backtracking regs (is, set, literal string, min,max=1,1)
// TODO: stack offsets instead of backtrack

static uint32_t	exec_reg_n(t_rmatch *m, t_reg const *reg, uint32_t offset, uint32_t n)
{
	uint32_t		tmp;

	if (reg->flags & REG_F_MINIMAL && n >= reg->min
		&& (tmp = exec_reg(m, reg->next, offset)) != REG_FAIL)
		return (tmp);
	if (n < reg->max // n + 1 < reg->max
		&& (tmp = g_exec_regs[reg->type](m, reg, offset)) != REG_FAIL
		&& (tmp = exec_reg_n(m, reg, offset + tmp, n + 1)) != REG_FAIL)
		return (tmp);
	if (n < reg->min)
		return (REG_FAIL);
	if (reg->next == NULL)
		return (offset);
	return (exec_reg(m, reg->next, offset));
}

uint32_t		exec_reg(t_rmatch *m, t_reg const *reg, uint32_t offset)
{
	uint32_t		tmp;

	while (reg != NULL)
	{
		if ((tmp = exec_reg_n(m, reg, offset, 0)) != REG_FAIL)
			return ((reg->flags & REG_F_ASSERT) ? offset : tmp);
		reg = reg->or_next;
	}
	return (REG_FAIL);
}
