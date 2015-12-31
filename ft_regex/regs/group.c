/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 20:26:19 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 20:21:00 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"
#include <stdlib.h>

uint32_t		parse_reg_group(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg_group *const	r = MAL1(t_reg_group);
	t_reg				**tmp;
	uint32_t			start;

	r->reg.type = REG_T_GROUP;
	r->group = NULL;
	tmp = &r->group;
	offset++;
	while (offset < p->len && p->str[offset] != ')')
	{
		start = offset;
		while (offset < p->len && p->str[offset] != '?'
			&& p->str[offset] != ')')
			offset++;
		if (start == offset)
			offset = parse_reg(p, offset + 1, tmp);
		else
			*tmp = create_reg_str(SUB(p->str + start, offset - start));
		if (offset == REG_FAIL)
			return (destroy_reg(r->group), free(r), REG_FAIL);
		tmp = &(*tmp)->next;
	}
	if (offset >= p->len)
		return (destroy_reg(r->group), free(r), REG_FAIL);
	*reg = V(r);
	return (offset + 1);
}
