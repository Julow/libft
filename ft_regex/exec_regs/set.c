/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 22:28:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_set(t_rmatch *m, t_reg_set const *reg, uint32_t offset)
{
	if (offset < m->len && m->str[offset] > 0)
	{
		if (BITARRAY_GET(reg->set, (uint8_t)m->str[offset]))
			return (offset + 1);
		if (reg->reg.flags & REG_F_ICASE
			&& BITARRAY_GET(reg->set, (uint8_t)LOWER(m->str[offset])))
			return (offset + 1);
	}
	return (REG_FAIL);
}
