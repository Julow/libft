/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 17:37:42 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 17:52:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"
#include "regex_internal.h"

/*
** Have to alloc the t_reg struct and set the 'type' property
** Should set '*reg' to NULL on error
*/
static uint32_t	(*g_parse_reg_type[((uint8_t)-1)>>1])(t_parse_reg*, uint32_t, t_reg**) = {
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
		return ((*named = false), offset);
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
			n = MAL1(t_parse_reg_n);
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

static uint32_t	parse_n(t_parse_reg *p, uint32_t offset,
					uint32_t *min, uint32_t *max)
{
	char			c;

	if (offset >= p->len)
		return (offset);
	c = p->str[offset];
	if (c == '?')
		return (*min = 0, *max = 1, offset + 1);
	else if (c == '*')
		return (*min = 0, *max = REG_INFINITY, offset + 1);
	else if (c == '+')
		return (*min = 1, *max = REG_INFINITY, offset + 1);
	else if (IS(c, IS_DIGIT))
		offset += ft_subint(SUB(p->str + offset, p->len - offset), min);
	else
		*min = 1;
	if (offset < p->len && p->str[offset] == ',')
	{
		if (++offset < p->len && IS(p->str[offset], IS_DIGIT))
			offset += ft_subint(SUB(p->str + offset,
					p->len - offset), max);
		else
			*max = REG_INFINITY;
	}
	else
		*max = *min;
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
		offset += ft_subint(SUB(p->str + offset, p->len - offset), capture_i);
	else
		*capture_i = p->capture_index++;
	p->capture_count++;
	*flags |= REG_F_CAPTURE;
	return (offset);
}

uint32_t		parse_reg(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	uint32_t		min;
	uint32_t		max;
	uint32_t		flags;
	uint32_t		capture_index;
	bool			reg_named;
	uint32_t		(*f)(t_parse_reg*, uint32_t, t_reg**);

	flags = 0;
	if ((offset = parse_name(p, offset, &reg_named, &flags)) == REG_FAIL)
		return (REG_FAIL);
	offset = parse_flags(p, offset, &flags);
	offset = parse_n(p, offset, &min, &max);
	offset = parse_capture(p, offset, &capture_index, &flags);
	if (offset >= p->len || p->str[offset] < 0
		|| (f = g_parse_reg_type[(uint8_t)p->str[offset]]) == NULL)
		return (REG_ERROR(p, "Unsupported reg", offset));
	if ((offset = f(p, offset, reg)) == REG_FAIL)
		return (REG_FAIL);
	if (reg_named)
		p->named_regs->reg = *reg;
	(*reg)->min = min;
	(*reg)->max = max;
	(*reg)->flags = flags;
	(*reg)->capture_index = capture_index;
	(*reg)->or_next = NULL;
	(*reg)->next = NULL;
	if (offset < p->len && p->str[offset] == '|')
		offset = parse_reg(p, offset + 1, &((*reg)->or_next));
	return (offset);
}
