/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcompile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:18:40 by juloo             #+#    #+#             */
/*   Updated: 2016/07/06 21:54:51 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"
#include <stdlib.h>

#define FUCK(...)		(__VA_ARGS__)

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

static t_reg	*compile_regex(t_parse_reg *p)
{
	t_reg			*reg;

	if (parse_regex(p, 0, &reg, '\0') == REG_FAIL)
		return (NULL);
	p->capture_index = 0;
	if (check_capture_indexes(p, reg))
		return (reg);
	return (FUCK(destroy_reg(reg), NULL));
}

#define SUB_P(P)		(SUB((P)->str, (P)->len))

uint32_t		parse_regex(t_parse_reg *p, uint32_t offset, t_reg **reg,
					char end)
{
	t_reg			*r;
	t_reg			*tmp;
	uint32_t		start;
	uint32_t		next_end;

	*reg = NULL;
	r = NULL;
	next_end = (end == '\0') ? p->len : ft_subchr_e(SUB_P(p), offset, end);
	while (offset < next_end)
	{
		start = offset;
		if ((offset = ft_subchr_e(SUB(p->str, p->len), offset, '?')) > next_end)
			offset = next_end;
		if (start != offset)
			tmp = create_reg_str(SUB(p->str + start, offset - start));
		else if ((offset = parse_reg(p, offset + 1, &tmp)) == REG_FAIL)
			return (FUCK(destroy_reg(*reg), (*reg = NULL), REG_FAIL));
		if (offset >= next_end && end != '\0')
			next_end = ft_subchr_e(SUB(p->str, p->len), offset, end);
		r = append_reg_next(r, tmp);
		if (*reg == NULL)
			*reg = r;
	}
	return ((end == '\0' || offset < p->len) ? offset : FUCK((void)REG_ERROR(p,
		"Unclosed group", offset), destroy_reg(*reg), (*reg = NULL), REG_FAIL));
}

bool			ft_rcompile(t_regex *dst, t_sub pattern, t_regex_err *err)
{
	t_parse_reg		parser;

	parser = (t_parse_reg){pattern.str, pattern.length, 0, 0, NULL, 0, SUB0()};
	dst->reg = compile_regex(&parser);
	dst->capture_count = parser.capture_index;
	if (dst->reg == NULL && err != NULL)
		*err = (t_regex_err){parser.err_str, parser.err_offset};
	destroy_parser(&parser);
	return (BOOL_OF(dst->reg != NULL));
}
