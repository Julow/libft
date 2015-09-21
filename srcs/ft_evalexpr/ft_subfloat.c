/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:21:00 by juloo             #+#    #+#             */
/*   Updated: 2015/09/21 12:36:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"

#define RETURN(...)		return (__VA_ARGS__)

static int		sub_float(t_sub sub, t_bool neg, float *f)
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

int				ft_subfloat(t_sub sub, float *f)
{
	int				i;
	float			tmp;
	t_bool			negative;

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
