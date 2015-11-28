/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 20:25:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_rmatch.h"
#include "rmatch_internal.h"

#define MATCH_NOT(r,f)	(((r)->flags & FLAG_R_NOT) ? !(f) : (f))
#define MATCH_I(r,c)	(((r)->flags & FLAG_R_CASE) ? LOWER(c) : (c))

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

static t_bool	reg_match_sub(t_reg *reg, const char **str)
{
	char			tmp[reg->reg_len + 1];
	const char		*ptr = tmp;

	if (reg->reg_len == 0)
		return (false);
	ft_memcpy(tmp, reg->reg, reg->reg_len);
	tmp[reg->reg_len] = '\0';
	while (*ptr != '\0')
	{
		if (*ptr == REG_START)
			return (((*str = reg_match(*str, &ptr)) == NULL) ? false : true);
		else if (MATCH_NOT(reg, MATCH_I(reg, **str) != *(ptr++)))
			return (false);
		(*str)++;
	}
	return (true);
}

static t_bool	reg_match_str(t_reg *reg, const char **str)
{
	if (reg->reg_len == 0)
		return (false);
	if (reg->flags & FLAG_R_CASE)
	{
		if (MATCH_NOT(reg, ft_strncase(*str, reg->reg, reg->reg_len)))
			return (false);
	}
	else if (MATCH_NOT(reg, ft_memcmp(*str, reg->reg, reg->reg_len) != 0))
		return (false);
	return (((*str) += reg->reg_len), true);
}

static t_bool	reg_match_1(t_reg *reg, const char **str)
{
	int				c;

	if (**str == '\0')
		return (false);
	if (reg->flags & FLAG_R_PRE)
	{
		(*str) += (c = ((int (*)(const char*))reg->reg)(*str));
		if (c == 0 && reg->flags & FLAG_R_NOT)
			(*str)++;
		return (MATCH_NOT(reg, (c > 0)));
	}
	else if (reg->flags & FLAG_R_IS)
		return (MATCH_NOT(reg, IS(*((*str)++), reg->reg_len)));
	else if (reg->flags & FLAG_R_SET)
	{
		c = MATCH_I(reg, (**str));
		return (((*str)++), MATCH_NOT(reg, reg_match_set(reg, c)));
	}
	else if (reg->flags & FLAG_R_SUB)
		return (reg_match_sub(reg, str));
	return (reg_match_str(reg, str));
}

const char		*reg_reg(t_reg *r, const char *s, const char *p, t_uint l)
{
	char const		*tmp;

	tmp = s;
	if (reg_match_1(r, &s) && l < r->to
		&& (s = reg_reg(r, s, p, l + 1)) != NULL)
		return (s);
	if (l >= r->from && (tmp = reg_test(tmp, p)) != NULL)
		return (tmp);
	return (NULL);
}
