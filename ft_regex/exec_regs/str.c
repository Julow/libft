/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/02/10 17:28:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_str(t_rmatch *m, t_reg_str const *reg, uint32_t offset)
{
	if (BOOL_OF(m->str.length - offset >= reg->str.length
			&& ((reg->reg.flags & REG_F_ICASE && ft_subequi(
				SUB(m->str.str + offset, reg->str.length), reg->str))
			|| ft_memcmp(m->str.str + offset,
				reg->str.str, reg->str.length) == 0))
		^ BOOL_OF(reg->reg.flags & REG_F_NOT))
		return (offset + reg->str.length);
	return (REG_FAIL);
}
