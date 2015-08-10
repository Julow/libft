/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:21:00 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 14:59:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"

int				ft_subfloat(t_sub sub, float *f)
{
	int				i;
	float			dec;
	t_bool			negative;

	*f = 0.f;
	if (sub.length <= 0)
		return (0);
	negative = (sub.str[0] == '-') ? true : false;
	i = (sub.str[0] == '-' || sub.str[0] == '+') ? 1 : 0;
	while (i < sub.length && IS(sub.str[i], IS_DIGIT))
		*f = *f * 10.f + (float)(sub.str[i++] - '0');
	if (negative)
		*f = -(*f);
	if (i >= sub.length || (sub.str[i] != '.' && sub.str[i] != ','))
		return (i);
	dec = 0.f;
	while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
		dec = (dec + (float)(sub.str[i] - '0')) / 10.f;
	*f += negative ? -dec : dec;
	return (i);
}
