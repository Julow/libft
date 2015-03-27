/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:13:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 23:59:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

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
			if (!reg_match(*str, reg->reg + i))
				return (false);
		}
		else if ((*str)[i] != reg->reg[i])
			return (false);
	}
	*str += (i == 0) ? 1 : i;
	return (true);
}

static t_bool	reg_match_1(t_reg *reg, const char **str)
{
	if (reg->flags & FLAG_R_F)
	{
		if (reg->reg == NULL)
			return (false);
		return (((t_bool (*)(char))reg->reg)(*((*str)++)));
	}
	else if (reg->flags & FLAG_R_SET)
		return (reg_match_set(reg, *((*str)++)));
	else
		return (reg_match_str(reg, str));
}

static void		skip_or(const char **pattern)
{
	t_reg			tmp;

	while (**pattern == '|')
		*pattern = reg_parse(&tmp, *pattern + 1);
}

t_bool			reg_match(const char *str, const char *pattern)
{
	t_reg			reg;
	t_uint			i;

	pattern = reg_parse(&reg, pattern + 1);
	if (*pattern == '|')
	{
		if (reg_match(str, pattern))
			return (true);
		skip_or(&pattern);
	}
	i = -1;
	while (++i < reg.to)
	{
		if (i >= reg.from && ft_rmatch(str, pattern))
			return (true);
		if (!reg_match_1(&reg, &str))
			return (false);
	}
	return (ft_rmatch(str, pattern));
}
