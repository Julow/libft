/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wbound.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/02/10 17:27:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_wbound(t_rmatch *m, t_reg_wbound const *reg, uint32_t offset)
{
	if (offset == 0 || !IS(m->str.str[offset - 1], IS_WORD))
	{
		if (offset < m->str.length && IS(m->str.str[offset], IS_WORD))
			return ((reg->flags & REG_F_NOT) ? REG_FAIL : offset);
	}
	else if (offset == m->str.length || !IS(m->str.str[offset], IS_WORD))
	{
		if (offset > 0 && IS(m->str.str[offset - 1], IS_WORD))
			return ((reg->flags & REG_F_NOT) ? REG_FAIL : offset);
	}
	return ((reg->flags & REG_F_NOT) ? offset : REG_FAIL);
	(void)reg;
}
