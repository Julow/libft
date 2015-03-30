/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_parse_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:21:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 13:22:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

const char		*parse_reg_pre(t_reg *reg, const char *pattern)
{
	if (*pattern == 'i')
		reg->reg = (char*)&ft_matchint;
	else
		reg->reg = NULL;
	reg->flags |= FLAG_R_PRE;
	return (pattern + 1);
}

const char		*parse_reg_is(t_reg *reg, const char *pattern)
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
	reg->flags |= FLAG_R_IS;
	return (pattern + 1);
}

const char		*parse_reg_sub(t_reg *reg, const char *str)
{
	int					i;
	t_reg				tmp;

	reg->reg = (char*)str;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == REG_START)
			i += reg_parse(&tmp, str) - str;
		else if (str[i] == ')')
			break ;
		else
			i++;
	}
	reg->reg_len = i;
	reg->flags |= FLAG_R_SUB;
	return (str + i + 1);
}
