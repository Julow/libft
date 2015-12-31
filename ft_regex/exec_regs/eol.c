/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 22:26:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_eol(t_rmatch *m, t_reg_eol const *reg, uint32_t offset)
{
	if (m->len <= offset)
		return (offset);
	return (REG_FAIL);
	(void)reg;
}
