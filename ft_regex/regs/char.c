/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 19:32:34 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 20:34:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		parse_reg_char(t_sub pattern, uint32_t offset, t_reg **reg)
{
	t_reg_char		*r;

	offset++;
	if (offset >= pattern.length)
		return (REG_FAIL);
	r = MAL1(t_reg_char);
	r->reg.type = REG_T_CHAR;
	r->c = pattern.str[offset];
	*reg = V(r);
	return (offset + 1);
}
