/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 21:01:19 by juloo             #+#    #+#             */
/*   Updated: 2016/07/06 21:49:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

#define RETURN(...)		return (__VA_ARGS__)

static uint32_t	g_reg_type_sizeof[__REG_T_COUNT] = {
	[REG_T_STR] = sizeof(t_reg_str),
	[REG_T_SET] = sizeof(t_reg_set),
	[REG_T_GROUP] = sizeof(t_reg_group),
	[REG_T_SOL] = sizeof(t_reg_sol),
	[REG_T_EOL] = sizeof(t_reg_eol),
	[REG_T_WBOUND] = sizeof(t_reg_wbound),
};

static bool		parse_reg_block_named(t_parse_reg *p, t_sub sub,
					uint32_t start, t_reg **reg)
{
	uint32_t		size;
	t_reg_group		*r;
	t_parse_reg_n	*n;

	n = p->named_regs;
	while (n != NULL)
	{
		if (ft_subequ(sub, n->name))
		{
			if (n->reg == NULL || (size = g_reg_type_sizeof[n->reg->type]) == 0)
				RETURN((void)REG_ERROR(p, "Unsupported named reg", start),
					false);
			r = MALLOC(sizeof(t_reg_group) + size);
			r->reg.type = REG_T_GROUP;
			r->group = ENDOF(r);
			ft_memcpy(r->group, n->reg, size);
			r->group->flags &= ~REG_F_UNUSED;
			r->group->next = NULL;
			*reg = V(r);
			return (true);
		}
		n = n->prev;
	}
	RETURN((void)REG_ERROR(p, "Unknown reg", start), false);
}

static bool		parse_reg_block_cstr(t_parse_reg *p, t_sub sub,
					uint32_t start, t_reg **reg)
{
	t_reg_cstr		*r;
	uint32_t		index;
	uint32_t		tmp;

	tmp = ft_subto_uint(sub, &index);
	if (tmp < sub.length || sub.length == 0)
		RETURN((void)REG_ERROR(p, "Invalid capture index", start), false);
	r = NEW(t_reg_cstr);
	r->reg.type = REG_T_CSTR;
	r->index = index;
	*reg = V(r);
	return (true);
}

uint32_t		parse_reg_block(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	uint32_t const	start = ++offset;
	t_sub			sub;
	bool			tmp;

	while (offset < p->len && p->str[offset] != '}')
		offset++;
	if (start >= offset || offset >= p->len)
		return (REG_ERROR(p, "Unclosed name braces", start));
	sub = SUB(p->str + start, offset - start);
	if (p->str[start] == ':')
		tmp = parse_reg_block_is(SUB(sub.str + 1, sub.length - 1), reg);
	else if (p->str[start] == '&')
		tmp = parse_reg_block_cstr(p, SUB(sub.str + 1, sub.length - 1),
				start, reg);
	else
		tmp = parse_reg_block_named(p, sub, start, reg);
	if (!tmp)
		return (REG_FAIL);
	return (offset + 1);
}
