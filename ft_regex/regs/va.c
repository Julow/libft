/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 13:54:47 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 18:13:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		parse_reg_va(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	uint32_t		index;
	t_reg_va_t		type;
	t_reg_va		*r;

	offset++;
	if (offset >= p->len)
		return (REG_FAIL);
	if (IS(p->str[offset], IS_DIGIT))
		offset += ft_subint(SUB(p->str + offset, p->len - offset), &index);
	else
		index = p->va_index++;
	if (p->str[offset] == 's')
		type = REG_VA_T_SUB;
	else if (p->str[offset] == 'S')
		type = REG_VA_T_STR;
	else if (p->str[offset] == 'r')
		type = REG_VA_T_REGEX;
	else
		return (REG_FAIL);
	r = MAL1(t_reg_va);
	r->reg.type = REG_T_VA;
	r->index = index;
	r->type = type;
	*reg = V(r);
	return (offset + 1);
}
