/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 20:26:19 by juloo             #+#    #+#             */
/*   Updated: 2016/01/19 16:10:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"
#include <stdlib.h>

uint32_t		parse_reg_group(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg			*group;
	t_reg_group 	*r;

	if ((offset = parse_regex(p, offset + 1, &group, ')')) == REG_FAIL)
		return (REG_FAIL);
	r = NEW(t_reg_group);
	r->reg.type = REG_T_GROUP;
	r->group = group;
	*reg = V(r);
	return (offset + 1);
}
