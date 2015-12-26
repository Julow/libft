/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcompile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:18:40 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 18:15:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"
#include "regex_internal.h"

uint32_t		parse_reg_flags(t_sub pattern, uint32_t offset, uint32_t *flags)
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

uint32_t		parse_reg_n(t_sub pattern, uint32_t offset,
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

/*
** Have to alloc the t_reg struct and set the 'type' property
** Should set '*reg' to NULL on error
*/
uint32_t		(*g_parse_reg_type[(uint8_t)-1])(t_sub, uint32_t, t_reg**) = {
	['.'] = &parse_reg_type_is,
	['a'] = &parse_reg_type_is,
	['l'] = &parse_reg_type_is,
	['u'] = &parse_reg_type_is,
	['d'] = &parse_reg_type_is,
	['n'] = &parse_reg_type_is,
	['s'] = &parse_reg_type_is,
	['w'] = &parse_reg_type_is,
	// TODO [':'] = &parse_reg_type_char,
	// TODO ['b'] = &parse_reg_type_wbound,
	// TODO ['$'] = &parse_reg_type_eol,
	['<'] = &parse_reg_type_is,
	['\''] = &parse_reg_type_str,
	['"'] = &parse_reg_type_str,
	['['] = &parse_reg_type_set,
	// TODO ['('] = &parse_reg_type_group,
	// TODO ['{'] = &parse_reg_type_named,
};

uint32_t		parse_reg(t_sub pattern, uint32_t offset, t_reg **reg)
{
	uint32_t		min;
	uint32_t		max;
	uint32_t		flags;
	uint32_t		(*f)(t_sub, uint32_t, t_reg**);

	offset = parse_reg_flags(pattern, offset, &flags);
	offset = parse_reg_n(pattern, offset, &min, &max);
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

uint32_t		parse_regex(t_sub pattern, uint32_t offset, t_reg **reg)
{
	uint32_t const	start = offset;

	while (offset < pattern.length && pattern.str[offset] != '?')
		offset++;
	if (start == offset)
		return (parse_reg(pattern, offset + 1, reg));
	*reg = create_reg_str(SUB(pattern.str + start, offset - start));
	(*reg)->min = 1;
	(*reg)->max = 1;
	(*reg)->flags = 0;
	(*reg)->or_next = NULL;
	(*reg)->next = NULL;
	return (offset);
}

bool			ft_rcompile(t_regex *dst, t_sub pattern)
{
	t_reg			*last;
	t_reg			*tmp;
	uint32_t		offset;

	offset = 0;
	dst->reg = NULL;
	while (offset < pattern.length)
	{
		if ((offset = parse_regex(pattern, offset, &tmp)) == REG_FAIL)
			return (destroy_reg(dst->reg), false);
		if (dst->reg == NULL)
			dst->reg = tmp;
		else
			last->next = tmp;
		last = tmp;
	}
	return (true);
}
