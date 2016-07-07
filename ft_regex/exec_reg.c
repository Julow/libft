/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:27:12 by juloo             #+#    #+#             */
/*   Updated: 2016/07/07 14:42:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static t_exec_reg	g_exec_regs[__REG_T_COUNT] = {
	[REG_T_STR] = {V(&exec_reg_str), false},
	[REG_T_SET] = {V(&exec_reg_set), true},
	[REG_T_GROUP] = {V(&exec_reg_group), false},
	[REG_T_EOL] = {V(&exec_reg_eol), false},
	[REG_T_SOL] = {V(&exec_reg_sol), false},
	[REG_T_WBOUND] = {V(&exec_reg_wbound), false},
	[REG_T_CSTR] = {V(&exec_reg_cstr), false},
};

static uint32_t	exec_reg_n(t_rmatch *m, t_reg const *reg, t_vec2u offsets,
					uint32_t n)
{
	uint32_t		tmp;

	if (reg->flags & REG_F_MINIMAL && n >= reg->min
		&& (tmp = exec_reg_next(m, reg, offsets.x, offsets.y) != REG_FAIL))
		return (tmp);
	if (n < reg->max
		&& (tmp = g_exec_regs[reg->type].exec(m, reg, offsets.y)) != REG_FAIL
		&& (tmp != offsets.y || n < reg->min)
		&& (tmp = exec_reg_n(m, reg, VEC2U(tmp, offsets.x), n + 1)) != REG_FAIL)
		return (tmp);
	if (n >= reg->min)
		return (exec_reg_next(m, reg, offsets.y, offsets.x));
	return (REG_FAIL);
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
		tmp = (g_exec_regs[reg->type].no_bt)
			? g_exec_regs[reg->type].exec(m, reg, offset)
			: exec_reg_n(m, reg, VEC2U(offset, offset), 0);
		if (tmp != REG_FAIL)
			return (tmp);
		reg = reg->or_next;
	}
	return (REG_FAIL);
}

uint32_t		exec_reg_next(t_rmatch *m, t_reg const *reg,
					uint32_t start, uint32_t offset)
{
	uint32_t		tmp;

	tmp = (reg->flags & REG_F_ASSERT) ? start : offset;
	if (reg->flags & REG_F_CAPTURE && reg->capture_index < m->capture_count)
		m->captures[reg->capture_index] =
			SUB(m->str.str + start, offset - start);
	if (reg->next == NULL)
		return (tmp);
	return (exec_reg(m, reg->next, tmp));
}
