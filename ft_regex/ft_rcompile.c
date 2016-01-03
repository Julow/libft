/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcompile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:18:40 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 17:16:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"
#include <stdlib.h>

static void		destroy_parser(t_parse_reg *p)
{
	t_parse_reg_n	*n;
	t_parse_reg_n	*tmp;

	n = p->named_regs;
	while (n != NULL)
	{
		tmp = n;
		n = n->prev;
		free(tmp);
	}
}

static bool		check_capture_indexes(t_parse_reg *p, t_reg *reg)
{
	while (reg != NULL)
	{
		if (reg->flags & REG_F_CAPTURE
			&& reg->capture_index >= p->capture_index)
			p->capture_index = reg->capture_index + 1;
		if ((reg->flags & REG_F_CAPTURE
				&& reg->capture_index >= p->capture_count)
			|| (reg->or_next != NULL
				&& !check_capture_indexes(p, reg->or_next))
			|| (reg->type == REG_T_GROUP
				&& !check_capture_indexes(p, ((t_reg_group*)reg)->group)))
			break ;
		reg = reg->next;
	}
	if (reg == NULL)
		return (true);
	REG_ERROR(p, "Discontinuous capture indexes", 0);
	return (false);
}

static t_reg	*parse_regex(t_parse_reg *p)
{
	t_reg			*first;
	t_reg			*reg;
	t_reg			*tmp;
	uint32_t		start;
	uint32_t		offset;

	offset = 0;
	first = NULL;
	reg = NULL;
	while (offset < p->len)
	{
		start = offset;
		while (offset < p->len && p->str[offset] != '?')
			offset++;
		if (start == offset)
			offset = parse_reg(p, offset + 1, &tmp);
		else
			tmp = create_reg_str(SUB(p->str + start, offset - start));
		if (offset == REG_FAIL)
			return (destroy_reg(first), NULL);
		reg = append_reg_next(reg, tmp);
		if (first == NULL)
			first = reg;
	}
	p->capture_index = 0;
	if (check_capture_indexes(p, first))
		return (first);
	return (destroy_reg(first), NULL);
}

bool			ft_rcompile(t_regex *dst, t_sub pattern, t_regex_err *err)
{
	t_parse_reg		parser;

	parser = (t_parse_reg){pattern.str, pattern.length, 0, 0, NULL, 0, SUB0()};
	dst->reg = parse_regex(&parser);
	dst->capture_count = parser.capture_index;
	if (dst->reg == NULL && err != NULL)
		*err = (t_regex_err){parser.err_str, parser.err_offset};
	destroy_parser(&parser);
	return (BOOL_OF(dst->reg != NULL));
}
