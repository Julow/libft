/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 17:37:42 by juloo             #+#    #+#             */
/*   Updated: 2015/12/27 17:38:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"
#include "regex_internal.h"

/*
** Have to alloc the t_reg struct and set the 'type' property
** Should set '*reg' to NULL on error
*/
uint32_t		(*g_parse_reg_type[(uint8_t)-1])(t_sub, uint32_t, t_reg**) = {
	['.'] = &parse_reg_is,
	['a'] = &parse_reg_is,
	['l'] = &parse_reg_is,
	['u'] = &parse_reg_is,
	['d'] = &parse_reg_is,
	['n'] = &parse_reg_is,
	['s'] = &parse_reg_is,
	['w'] = &parse_reg_is,
	[':'] = &parse_reg_char,
	['b'] = &parse_reg_wbound,
	['$'] = &parse_reg_eol,
	['<'] = &parse_reg_is,
	['\''] = &parse_reg_str,
	['"'] = &parse_reg_str,
	['['] = &parse_reg_set,
	['('] = &parse_reg_group,
	// TODO ['{'] = &parse_reg_named,
};

static uint32_t	parse_flags(t_sub pattern, uint32_t offset, uint32_t *flags)
{
	char			c;

	while (offset < pattern.length)
	{
		c = pattern.str[offset];
		if (c == '!')
			*flags |= REG_F_NOT;
		else if (c == 'i')
			*flags |= REG_F_ICASE;
		else if (c == '=')
			*flags |= REG_F_ASSERT;
		else if (c == '_')
			*flags |= REG_F_MINIMAL;
		else
			break ;
		offset++;
	}
	return (offset);
}

static uint32_t	parse_n(t_sub pattern, uint32_t offset,
					uint32_t *min, uint32_t *max)
{
	char			c;

	if (offset >= pattern.length)
		return (offset);
	c = pattern.str[offset];
	if (c == '?')
		return (*min = 0, *max = 1, offset + 1);
	else if (c == '*')
		return (*min = 0, *max = -1, offset + 1);
	else if (c == '+')
		return (*min = 1, *max = -1, offset + 1);
	else if (IS(c, IS_DIGIT))
		offset += ft_subint(SUB(pattern.str + offset, pattern.length - offset),
			min);
	else
		*min = 1;
	if (offset < pattern.length && pattern.str[offset] == ',')
	{
		if (++offset < pattern.length && IS(pattern.str[offset], IS_DIGIT))
			offset += ft_subint(SUB(pattern.str + offset,
					pattern.length - offset), max);
		else
			*max = -1;
	}
	else
		*max = *min;
	return (offset);
}

uint32_t		parse_reg(t_sub pattern, uint32_t offset, t_reg **reg)
{
	uint32_t		min;
	uint32_t		max;
	uint32_t		flags;
	uint32_t		(*f)(t_sub, uint32_t, t_reg**);

	offset = parse_flags(pattern, offset, &flags);
	offset = parse_n(pattern, offset, &min, &max);
	if (offset < pattern.length
		&& (f = g_parse_reg_type[pattern.str[offset]]) != NULL)
		offset = f(pattern, offset, reg);
	else
		return (REG_FAIL);
	(*reg)->min = min;
	(*reg)->max = max;
	(*reg)->flags = flags;
	(*reg)->or_next = NULL;
	(*reg)->next = NULL;
	if (offset < pattern.length && pattern.str[offset] == '|')
		offset = parse_reg(pattern, offset + 1, &((*reg)->or_next));
	return (offset);
}
