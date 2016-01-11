/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:38:31 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/11 19:42:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

int				ft_subto_int(t_sub sub, int *dst)
{
	int			tmp;
	int			i;

	tmp = 0;
	i = -1;
	while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
		tmp = tmp * 10 + sub.str[i] - '0';
	*dst = tmp;
	return (i);
}

#define RETURN(...)		return (__VA_ARGS__)

static int		sub_float(t_sub sub, bool neg, float *f)
{
	int				i;
	int				base_i;
	t_sub			base;
	float			tmp;

	if (sub.length <= 0)
		RETURN((*f = 0.f), 0);
	if (sub.str[0] == 'X' || sub.str[0] == 'x')
		base = SUBC(BASE_16);
	else if (sub.str[0] == 'b')
		base = SUBC(BASE_2);
	tmp = 0.f;
	i = 0;
	while (++i < sub.length
		&& (base_i = ft_subindex(base, UPPER(sub.str[i]))) >= 0)
		tmp = tmp * ((float)base.length) + ((float)base_i);
	*f = neg ? -tmp : tmp;
	if (i >= sub.length || (sub.str[i] != '.' && sub.str[i] != ','))
		return (i);
	tmp = 0.f;
	while (++i < sub.length
		&& (base_i = ft_subindex(base, UPPER(sub.str[i]))) >= 0)
		tmp = (tmp + (float)base_i) / (float)base.length;
	*f += neg ? -tmp : tmp;
	return (i);
}

int				ft_subto_float(t_sub sub, float *f)
{
	int				i;
	float			tmp;
	bool			negative;

	if (sub.length <= 0)
		RETURN((*f = 0.f), 0);
	negative = (sub.str[0] == '-') ? true : false;
	i = (negative || sub.str[0] == '+') ? 1 : 0;
	if ((i + 1) < sub.length && sub.str[i] == '0'
		&& (sub.str[++i] == 'X' || sub.str[i] == 'x' || sub.str[i] == 'b'))
		return (i + sub_float(SUB(sub.str + i, sub.length - i), negative, f));
	tmp = 0.f;
	while (i < sub.length && IS(sub.str[i], IS_DIGIT))
		tmp = tmp * 10.f + (float)(sub.str[i++] - '0');
	*f = negative ? -tmp : tmp;
	if (i >= sub.length || (sub.str[i] != '.' && sub.str[i] != ','))
		return (i);
	tmp = 0.f;
	while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
		;
	sub.length = i;
	while (sub.str[--i] != '.' && sub.str[i] != ',')
		tmp = (tmp + (float)(sub.str[i] - '0')) / 10.f;
	RETURN((*f += negative ? -tmp : tmp), sub.length);
}
