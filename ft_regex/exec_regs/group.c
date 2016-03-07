/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/03/07 14:53:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_group(t_rmatch *m, t_reg_group const *reg,
					uint32_t offset)
{
	uint32_t const	tmp = exec_reg(m, reg->group, offset);

	if (reg->reg.flags & REG_F_NOT)
		return ((tmp == REG_FAIL) ? offset : REG_FAIL);
	return (tmp);
}
