/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 17:37:42 by juloo             #+#    #+#             */
/*   Updated: 2016/06/18 15:51:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

#define FUCK(...)		__VA_ARGS__

typedef uint32_t		(*t_parse_reg_f)(t_parse_reg*, uint32_t, t_reg**);

/*
** Have to alloc the t_reg struct and set the 'type' property
** Should set '*reg' to NULL on error
*/
static t_parse_reg_f	g_parse_reg_type[((uint8_t)-1) >> 1] = {
	['.'] = &parse_reg_is,
	['a'] = &parse_reg_is,
	['l'] = &parse_reg_is,
	['u'] = &parse_reg_is,
	['d'] = &parse_reg_is,
	['n'] = &parse_reg_is,
	['s'] = &parse_reg_is,
	['w'] = &parse_reg_is,
	['b'] = &parse_reg_wbound,
	['^'] = &parse_reg_sol,
	['$'] = &parse_reg_eol,
	['\''] = &parse_reg_str,
	['"'] = &parse_reg_str,
	['['] = &parse_reg_set,
	['('] = &parse_reg_group,
	['{'] = &parse_reg_block,
};

static uint32_t	parse_name(t_parse_reg *p, uint32_t offset, bool *named,
					uint32_t *flags)
{
	uint32_t		start;
	t_parse_reg_n	*n;

	if (offset >= p->len || p->str[offset] != '#')
		return (FUCK((*named = false), offset));
	while (++offset < p->len)
		if (p->str[offset] == '#')
			*flags |= REG_F_UNUSED;
		else if (p->str[offset] != '{')
			break ;
		else
		{
			start = ++offset;
			while (offset < p->len && p->str[offset] != '}')
				offset++;
			if (offset >= p->len)
				break ;
			n = NEW(t_parse_reg_n);
			*n = (t_parse_reg_n){SUB(p->str + start, offset - start), NULL,
				p->named_regs};
			p->named_regs = n;
			*named = true;
			return (offset + 1);
		}
	return (REG_ERROR(p, "Invalid syntax", offset));
}

static uint32_t	parse_flags(t_parse_reg *p, uint32_t offset, uint32_t *flags)
{
	char			c;

	while (offset < p->len)
	{
		c = p->str[offset];
		if (c == '!')
			*flags |= REG_F_NOT;
		else if (c == 'i')
			*flags |= REG_F_ICASE;
		else if (c == '=')
			*flags |= REG_F_ASSERT;
		else if (c == '-')
			*flags |= REG_F_MINIMAL;
		else
			break ;
		offset++;
	}
	return (offset);
}

static uint32_t	parse_n(t_parse_reg *p, uint32_t offset, t_vec2u *range)
{
	char			c;

	if (offset >= p->len)
		return (offset);
	c = p->str[offset];
	if (c == '?')
		return (FUCK(*range = VEC2U(0, 1), offset + 1));
	else if (c == '*')
		return (FUCK(*range = VEC2U(0, REG_INFINITY), offset + 1));
	else if (c == '+')
		return (FUCK(*range = VEC2U(1, REG_INFINITY), offset + 1));
	else if (IS(c, IS_DIGIT))
		offset += ft_subto_uint(SUB(p->str + offset, p->len - offset),
				&range->x);
	else
		range->x = 1;
	if (offset > p->len || p->str[offset] != ',')
		range->y = range->x;
	else if (++offset < p->len && IS(p->str[offset], IS_DIGIT))
		offset += ft_subto_uint(SUB(p->str + offset, p->len - offset),
				&range->y);
	else
		range->y = REG_INFINITY;
	return (offset);
}

static uint32_t	parse_capture(t_parse_reg *p, uint32_t offset,
					uint32_t *capture_i, uint32_t *flags)
{
	if (offset >= p->len || p->str[offset] != '&')
	{
		*capture_i = 0;
		return (offset);
	}
	offset++;
	if (offset < p->len && IS(p->str[offset], IS_DIGIT))
		offset += ft_subto_uint(SUB(p->str + offset, p->len - offset),
				capture_i);
	else
		*capture_i = p->capture_index++;
	p->capture_count++;
	*flags |= REG_F_CAPTURE;
	return (offset);
}

uint32_t		parse_reg(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_vec2u			range;
	uint32_t		flags;
	uint32_t		capture_index;
	bool			reg_named;
	t_parse_reg_f	f;

	flags = 0;
	if ((offset = parse_name(p, offset, &reg_named, &flags)) == REG_FAIL)
		return (REG_FAIL);
	offset = parse_n(p, parse_flags(p, offset, &flags), &range);
	offset = parse_capture(p, offset, &capture_index, &flags);
	if (offset >= p->len || p->str[offset] < 0
		|| (f = g_parse_reg_type[(uint8_t)p->str[offset]]) == NULL)
		return (REG_ERROR(p, "Unsupported reg", offset));
	if ((offset = f(p, offset, reg)) == REG_FAIL)
		return (REG_FAIL);
	if (reg_named)
		p->named_regs->reg = *reg;
	**reg = (t_reg){range.x, range.y, flags,
			capture_index, (*reg)->type, NULL, NULL};
	return ((offset < p->len && p->str[offset] == '|') ?
			parse_reg(p, offset + 1, &((*reg)->or_next)) : offset);
}
