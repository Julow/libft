/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:21:00 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 01:02:34 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"

int				ft_subfloat(t_sub sub, float *f)
{
	int				i;
	float			dec;

	*f = 0.f;
	i = -1;
	while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
		*f = *f * 10.f + (float)(sub.str[i] - '0');
	if (i >= sub.length || (sub.str[i] != '.' && sub.str[i] != ','))
		return (i);
	dec = 0.f;
	while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
		dec = (dec + (float)(sub.str[i] - '0')) / 10.f;
	*f += dec;
	return (i);
}
