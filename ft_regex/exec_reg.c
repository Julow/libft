/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:27:12 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 20:45:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

#define REG_OFFSET()	((reg->flags & REG_F_ASSERT) ? start : offset)
#define REG_ISCAPTURE()	(reg->flags & REG_F_CAPTURE && m->captures != NULL)
#define REG_CAPTURE()	m->captures[reg->capture_index] = _REG_CAPTURE
#define _REG_CAPTURE	(SUB(m->str + start, offset - start))

static uint32_t	(*g_exec_regs[__REG_T_COUNT])(t_rmatch*, t_reg const*, uint32_t) = {
	[REG_T_STR] = &exec_reg_str,
	[REG_T_IS] = &exec_reg_is,
	[REG_T_SET] = &exec_reg_set,
	[REG_T_GROUP] = &exec_reg_group,
	[REG_T_EOL] = &exec_reg_eol,
	[REG_T_SOL] = &exec_reg_sol,
	[REG_T_WBOUND] = &exec_reg_wbound,
};

// TODO: non-backtracking regs (is, set, string, min,max=1,1)

static uint32_t	exec_reg_n(t_rmatch *m, t_reg const *reg, uint32_t offset,
					uint32_t start, uint32_t n)
{
	uint32_t		tmp;

	if (reg->flags & REG_F_MINIMAL && n >= reg->min
		&& (tmp = exec_reg(m, reg->next, REG_OFFSET())) != REG_FAIL)
	{
		if (REG_ISCAPTURE())
			REG_CAPTURE();
		return (tmp);
	}
	if (n < reg->max
		&& (tmp = g_exec_regs[reg->type](m, reg, offset)) != REG_FAIL
		&& (tmp = exec_reg_n(m, reg, tmp, start, n + 1)) != REG_FAIL)
		return (tmp);
	if (n < reg->min)
		return (REG_FAIL);
	if (REG_ISCAPTURE())
		REG_CAPTURE();
	if (reg->next == NULL)
		return (REG_OFFSET());
	return (exec_reg(m, reg->next, REG_OFFSET()));
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
