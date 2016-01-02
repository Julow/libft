/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 19:32:34 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 20:09:18 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		parse_reg_sol(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	*reg = V(MAL1(t_reg_sol));
	(*reg)->type = REG_T_SOL;
	return (offset + 1);
	(void)p;
}

uint32_t		parse_reg_eol(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	*reg = V(MAL1(t_reg_eol));
	(*reg)->type = REG_T_EOL;
	return (offset + 1);
	(void)p;
}
