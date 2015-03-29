/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:13:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/29 03:42:48 by jaguillo         ###   ########.fr       */
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
	char			tmp[reg->reg_len];
	const char		*ptr = tmp;

	if (reg->reg_len == 0)
		return (false);
	ft_memcpy(tmp, reg->reg, reg->reg_len);
	tmp[reg->reg_len] = '\0';
	while (*ptr != '\0')
	{
		if (*ptr == REG_START)
		{
			if ((*str = reg_match(*str, &ptr)) == NULL)
				return (false);
			continue ;
		}
		else if (MATCH_NOT(reg, **str != *(ptr++)))
			return (false);
		(*str)++;
	}
	return (true);
}

static t_bool	reg_match_1(t_reg *reg, const char **str)
{
	if (reg->reg == NULL || **str == '\0')
		return (false);
	if (reg->flags & FLAG_R_F)
		return (MATCH_NOT(reg, ((t_bool (*)(char))reg->reg)(*((*str)++))));
	else if (reg->flags & FLAG_R_SET)
		return (MATCH_NOT(reg, reg_match_set(reg, *((*str)++))));
	else
		return (reg_match_str(reg, str));
}

const char		*reg_reg(t_reg *r, const char *s, const char *p, t_uint l)
{
	char const		*tmp;

	if (!reg_match_1(r, &s))
		return (NULL);
	if (l < r->to && (tmp = reg_reg(r, s, p, l + 1)) != NULL)
		return (tmp);
	if (l >= r->from && (tmp = rmatch(s, p)) != NULL)
		return (tmp);
	return (NULL);
}

static void		skip_or(const char **pattern)
{
	t_reg			tmp;

	while (**pattern == '|')
		*pattern = reg_parse(&tmp, *pattern + 1);
}

const char		*reg_match(const char *str, const char **pattern)
{
	t_reg			reg;
	char const		*tmp;

	*pattern = reg_parse(&reg, (*pattern) + 1);
	if (**pattern == '|')
	{
		if ((tmp = reg_match(str, pattern)) != NULL)
			return (tmp);
		skip_or(pattern);
	}
	return (reg_reg(&reg, str, *pattern, 1));
}
