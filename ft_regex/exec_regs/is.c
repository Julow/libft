/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 17:57:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_is(t_rmatch *m, t_reg_is const *reg, uint32_t offset)
{
	if (offset >= m->len)
		return (REG_FAIL);
	if (BOOL_OF(IS(m->str[offset], reg->is) || (reg->reg.flags & REG_F_ICASE
			&& IS(LOWER(m->str[offset]), reg->is)))
		^ BOOL_OF(reg->reg.flags & REG_F_NOT))
		return (offset + 1);
	return (REG_FAIL);
}
