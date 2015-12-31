/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wbound.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 19:32:34 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 20:19:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		parse_reg_wbound(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	*reg = V(MAL1(t_reg_wbound));
	(*reg)->type = REG_T_WBOUND;
	return (offset + 1);
	(void)p;
}
