/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 20:07:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_sol(t_rmatch *m, t_reg_eol const *reg, uint32_t offset)
{
	if (BOOL_OF(offset == 0 || m->str[offset - 1] == '\n')
		^ BOOL_OF(reg->flags & REG_F_NOT))
		return (offset);
	return (REG_FAIL);
	(void)reg;
}

uint32_t		exec_reg_eol(t_rmatch *m, t_reg_eol const *reg, uint32_t offset)
{
	if (BOOL_OF(m->len <= offset || m->str[offset] == '\n')
		^ BOOL_OF(reg->flags & REG_F_NOT))
		return (offset);
	return (REG_FAIL);
	(void)reg;
}
