/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:13:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/29 00:38:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

#define MATCH_NOT(r,f)	(((r)->flags & FLAG_R_NOT) ? !(f) : (f))

static t_bool	reg_match_set(t_reg *reg, char c)
{
	int				i;

	i = -1;
	while (++i < reg->reg_len)
	{
		if (c == reg->reg[i])
			return (true);
		if ((i + 2) < reg->reg_len && reg->reg[i + 1] == '-')
		{
			if (c >= reg->reg[i] && c <= reg->reg[i + 2])
				return (true);
			i += 2;
		}
	}
	return (false);
}

static t_bool	reg_match_str(t_reg *reg, const char **str)
{
	int				i;

	i = -1;
	while (++i < reg->reg_len)
	{
		if (reg->reg[i] == REG_START)
		{
			if ((*str = reg_match(*str, reg->reg + i)) == NULL)
				return (false);
			continue ;
		}
		else if (MATCH_NOT(reg, **str != reg->reg[i]))
			return (false);
		(*str)++;
	}
	if (i == 0)
		(*str)++;
	return (true);
}

static t_bool	reg_match_1(t_reg *reg, const char **str)
{
	if (reg->flags & FLAG_R_F)
	{
		if (reg->reg == NULL)
			return (false);
		return (MATCH_NOT(reg, ((t_bool (*)(char))reg->reg)(*((*str)++))));
	}
	else if (reg->flags & FLAG_R_SET)
		return (MATCH_NOT(reg, reg_match_set(reg, *((*str)++))));
	else
		return (reg_match_str(reg, str));
}

static void		skip_or(const char **pattern)
{
	t_reg			tmp;

	while (**pattern == '|')
		*pattern = reg_parse(&tmp, *pattern + 1);
}

const char		*reg_match(const char *str, const char *pattern)
{
	t_reg			reg;
	t_uint			i;
	char const		*tmp;

	pattern = reg_parse(&reg, pattern + 1);
	// ft_printf("Match '%s' '%s'\n", str, pattern);
	// ft_printf("	(%x) ?%u,%u'%.*s' (%d)\n", reg.flags, reg.from, reg.to, reg.reg_len, reg.reg, reg.reg_len);
	if (*pattern == '|')
	{
		if ((tmp = reg_match(str, pattern)) != NULL)
			return (tmp);
		skip_or(&pattern);
	}
	i = -1;
	while (++i < reg.to)
	{
		if (i >= reg.from && (tmp = rmatch(str, pattern)) != NULL)
			return (tmp);
		if (!reg_match_1(&reg, &str))
			return (NULL);
	}
	return (rmatch(str, pattern));
}
