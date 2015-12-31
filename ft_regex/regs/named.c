/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   named.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 21:01:19 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 01:03:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static uint32_t	g_reg_type_sizeof[__REG_T_COUNT] = {
	[REG_T_STR] = sizeof(t_reg_str),
	[REG_T_CHAR] = sizeof(t_reg_char),
	[REG_T_IS] = sizeof(t_reg_is),
	[REG_T_SET] = sizeof(t_reg_set),
	[REG_T_GROUP] = sizeof(t_reg_group),
	[REG_T_EOL] = sizeof(t_reg_eol),
	[REG_T_WBOUND] = sizeof(t_reg_wbound),
};

uint32_t		parse_reg_named(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	uint32_t const	start = ++offset;
	uint32_t		size;
	t_reg_group		*r;
	t_parse_reg_n	*n;

	while (offset < p->len && p->str[offset] != '}')
		offset++;
	if (start >= offset || offset >= p->len)
		return (REG_FAIL);
	n = p->named_regs;
	while (n != NULL)
	{
		if (ft_subequ(SUB(p->str + start, offset - start), n->name))
		{
			if (n->reg == NULL || (size = g_reg_type_sizeof[n->reg->type]) == 0)
				return (REG_FAIL);
			r = ft_emalloc(sizeof(t_reg_group) + size);
			r->reg.type = REG_T_GROUP;
			r->group = ENDOF(r);
			ft_memcpy(r->group, n->reg, size);
			r->group->next = NULL;
			*reg = V(r);
			return (offset + 1);
		}
		n = n->prev;
	}
	return (REG_FAIL);
}
