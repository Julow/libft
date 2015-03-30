/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:14:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 13:22:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

static const char	*parse_reg_n(t_reg *reg, const char *pattern)
{
	pattern += ft_atoub(pattern, &(reg->from));
	if (*pattern == ',')
	{
		pattern++;
		if (ft_isdigit(*pattern))
			pattern += ft_atoub(pattern, &(reg->to));
		else
			reg->to = -1;
	}
	else
		reg->to = reg->from;
	return (pattern);
}

static const char	*parse_reg_r(t_reg *reg, const char *pattern)
{
	if (*pattern == '\'')
	{
		reg->reg = (char*)++pattern;
		reg->reg_len = ft_strcskipe(pattern, "'");
		return (pattern + reg->reg_len + 1);
	}
	else if (*pattern == '[')
	{
		reg->reg = (char*)++pattern;
		reg->reg_len = ft_strcskipe(pattern, "]");
		reg->flags |= FLAG_R_SET;
		return (pattern + reg->reg_len + 1);
	}
	else if (*pattern == '(')
		return (parse_reg_sub(reg, pattern + 1));
	else if (*pattern == ':')
	{
		reg->reg = (char*)++pattern;
		reg->flags |= FLAG_R_SET;
		reg->reg_len = 1;
		return (pattern + 1);
	}
	else if (*pattern == '&')
		return (parse_reg_pre(reg, pattern + 1));
	return (parse_reg_is(reg, pattern));
}

const char			*reg_parse(t_reg *reg, const char *pattern)
{
	*reg = (t_reg){0, 1, 1, 0, NULL};
	if (*pattern == '!' && pattern++)
		reg->flags |= FLAG_R_NOT;
	if (*pattern == 'i' && pattern++)
		reg->flags |= FLAG_R_CASE;
	if (ft_isdigit(*pattern))
		pattern = parse_reg_n(reg, pattern);
	else if (*pattern == '*' && pattern++)
	{
		reg->from = 0;
		reg->to = -1;
	}
	else if (*pattern == '?' && pattern++)
	{
		reg->from = 0;
		reg->to = 1;
	}
	else if (*pattern == '+' && pattern++)
	{
		reg->from = 1;
		reg->to = -1;
	}
	return (parse_reg_r(reg, pattern));
}
