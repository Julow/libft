/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:13:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 15:32:21 by jaguillo         ###   ########.fr       */
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
		if ((i + 2) < reg->reg_len)
		{
			if (reg->reg[i + 1] == '-'
				&& c >= reg->reg[i] && c <= reg->reg[i + 2])
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
	*str += i;
	return (true);
}

t_bool			reg_match(const char *str, const char *pattern)
{
	t_reg			reg;
	t_uint			i;

	pattern = reg_parse(&reg, pattern + 1);
	i = -1;
	while (++i < reg.to)
	{
		if (i >= reg.from && ft_rmatch(str, pattern))
			return (true);
		if (reg.flags & FLAG_R_F)
		{
			if (reg.reg == NULL || !(((t_bool (*)(char))reg.reg)(*(str++))))
				return (false);
		}
		else if (reg.flags & FLAG_R_SET)
		{
			if (!reg_match_set(&reg, *(str++)))
				return (false);
		}
		else if (!reg_match_str(&reg, &str))
			return (false);
	}
	return (ft_rmatch(str, pattern));
}
