/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 18:29:56 by juloo             #+#    #+#             */
/*   Updated: 2016/02/10 17:32:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_cstr(t_rmatch *m, t_reg_cstr const *reg, uint32_t offset)
{
	t_sub			sub;

	if (reg->index < m->capture_count)
		sub = m->captures[reg->index];
	else
		sub = SUB0();
	if (BOOL_OF(m->str.length - offset >= sub.length
			&& ((reg->reg.flags & REG_F_ICASE
				&& ft_subequi(SUB(m->str.str + offset, sub.length), sub))
			|| ft_memcmp(m->str.str + offset, sub.str, sub.length) == 0))
		^ BOOL_OF(reg->reg.flags & REG_F_NOT))
		return (offset + sub.length);
	return (REG_FAIL);
}
