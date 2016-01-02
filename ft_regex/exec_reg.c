/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:27:12 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 18:14:05 by juloo            ###   ########.fr       */
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

// TODO: non-backtracking regs (is, set, string, min,max=1,1)

static uint32_t	exec_reg_n(t_rmatch *m, t_reg const *reg, uint32_t offset,
					uint32_t start, uint32_t n)
{
	uint32_t		tmp;

	if (reg->flags & REG_F_MINIMAL && n >= reg->min
		&& (tmp = exec_reg(m, reg->next,
			(reg->flags & REG_F_ASSERT) ? start : offset)) != REG_FAIL)
		return (tmp);
	if (n < reg->max
		&& (tmp = g_exec_regs[reg->type](m, reg, offset)) != REG_FAIL
		&& (tmp = exec_reg_n(m, reg, tmp, start, n + 1)) != REG_FAIL)
		return (tmp);
	if (n < reg->min)
		return (REG_FAIL);
	if (reg->next == NULL)
		return ((reg->flags & REG_F_ASSERT) ? start : offset);
	return (exec_reg(m, reg->next,
		(reg->flags & REG_F_ASSERT) ? start : offset));
}

uint32_t		exec_reg(t_rmatch *m, t_reg const *reg, uint32_t offset)
{
	uint32_t		tmp;

	while (reg != NULL)
	{
		if (reg->flags & REG_F_UNUSED)
		{
			reg = reg->next;
			continue ;
		}
		if ((tmp = exec_reg_n(m, reg, offset, offset, 0)) != REG_FAIL)
			return (tmp);
		reg = reg->or_next;
	}
	return (REG_FAIL);
}
