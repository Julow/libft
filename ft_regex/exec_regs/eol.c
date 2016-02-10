/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/02/10 17:32:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		exec_reg_sol(t_rmatch *m, t_reg_sol const *reg, uint32_t offset)
{
	if (BOOL_OF(offset == 0 || m->str.str[offset - 1] == '\n')
		^ BOOL_OF(reg->flags & REG_F_NOT))
		return (offset);
	return (REG_FAIL);
	(void)reg;
}

uint32_t		exec_reg_eol(t_rmatch *m, t_reg_eol const *reg, uint32_t offset)
{
	if (BOOL_OF(m->str.length <= offset || m->str.str[offset] == '\n')
		^ BOOL_OF(reg->flags & REG_F_NOT))
		return (offset);
	return (REG_FAIL);
	(void)reg;
}
