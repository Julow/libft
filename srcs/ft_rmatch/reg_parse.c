/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:14:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/28 18:43:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

static const char	*ft_atoic(const char *str, t_uint *nb)
{
	int				sign;

	sign = 1;
	*nb = 0;
	while (ft_iswhite(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		*nb = *nb * 10 + (*(str++) - '0');
	*nb *= sign;
	return (str);
}

static const char	*parse_reg_n(t_reg *reg, const char *pattern)
{
	pattern = ft_atoic(pattern, &(reg->from));
	if (*pattern == ',')
	{
		pattern++;
		if (ft_isdigit(*pattern))
			pattern = ft_atoic(pattern, &(reg->to));
		else
			reg->to = -1;
	}
	else
		reg->to = reg->from;
	return (pattern);
}

static const char	*parse_reg_rf(t_reg *reg, const char *pattern)
{
	if (*pattern == 'w')
		reg->reg = (char*)&ft_isword;
	else if (*pattern == 'a')
		reg->reg = (char*)&ft_isalpha;
	else if (*pattern == 'n')
		reg->reg = (char*)&ft_isalnum;
	else if (*pattern == 'c' || *pattern == '.')
		reg->reg = (char*)&ft_isascii;
	else if (*pattern == 'd')
		reg->reg = (char*)&ft_isdigit;
	else if (*pattern == 'p')
		reg->reg = (char*)&ft_isprint;
	else if (*pattern == 's')
		reg->reg = (char*)&ft_isspace;
	else if (*pattern == 'h')
		reg->reg = (char*)&ft_iswhite;
	else
		reg->reg = NULL;
	reg->flags |= FLAG_R_F;
	return (pattern + 1);
}

static const char	*parse_reg_r(t_reg *reg, const char *pattern)
{
	if (*pattern == '\'')
	{
		reg->reg = (char*)++pattern;
		reg->reg_len = ft_strcskip(pattern, "'");
		pattern += reg->reg_len + 1;
	}
	else if (*pattern == '[')
	{
		reg->reg = (char*)++pattern;
		reg->reg_len = ft_strcskip(pattern, "]");
		reg->flags |= FLAG_R_SET;
		pattern += reg->reg_len + 1;
	}
	else if (*pattern == ':')
	{
		reg->reg = (char*)++pattern;
		reg->flags |= FLAG_R_SET;
		reg->reg_len = 1;
		pattern++;
	}
	else
		return (parse_reg_rf(reg, pattern));
	return (pattern);
}

const char			*reg_parse(t_reg *reg, const char *pattern)
{
	*reg = (t_reg){0, 1, 1, 0, NULL};
	if (*pattern == '!' && pattern++)
		reg->flags |= FLAG_R_NOT;
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
