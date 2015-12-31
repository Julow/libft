/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wbound.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 22:26:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_wbound(t_rmatch *m, t_reg_wbound const *reg, uint32_t offset)
{
	if (offset == 0 || !IS(m->str[offset - 1], IS_WORD))
	{
		if (offset < m->len && IS(m->str[offset], IS_WORD))
			return (offset);
	}
	else if (offset >= m->len || !IS(m->str[offset], IS_WORD))
	{
		if (offset < m->len && IS(m->str[offset - 1], IS_WORD))
			return (offset);
	}
	return (REG_FAIL);
	(void)reg;
}
