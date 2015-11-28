/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_parse_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:21:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:35 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_rmatch.h"
#include "rmatch_internal.h"

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
		reg->reg_len = IS_WORD;
	else if (*pattern == 'a')
		reg->reg_len = IS_ALPHA;
	else if (*pattern == 'n')
		reg->reg_len = IS_ALNUM;
	else if (*pattern == 'c' || *pattern == '.')
		reg->reg_len = -1;
	else if (*pattern == 'd')
		reg->reg_len = IS_DIGIT;
	else if (*pattern == 'p')
		reg->reg_len = IS_PRINT;
	else if (*pattern == 's')
		reg->reg_len = IS_SPACE;
	else if (*pattern == 'h')
		reg->reg_len = IS_WHITE;
	else
		reg->reg_len = 0;
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
