/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:38:31 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/11 23:10:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

uint32_t		ft_subto_int(t_sub sub, int32_t *dst)
{
	uint32_t		i;
	int32_t			n;
	bool			neg;

	neg = BOOL_OF(sub.length > 0 && sub.str[0] == '-');
	i = neg ? 1 : 0;
	n = 0;
	while (i < sub.length && IS(sub.str[i], IS_DIGIT))
	{
		n = n * 10 + sub.str[i] - '0';
		i++;
	}
	*dst = neg ? -n : n;
	return (i);
}

uint32_t		ft_subto_uint(t_sub sub, uint32_t *dst)
{
	uint32_t		i;
	uint32_t		n;

	i = 0;
	n = 0;
	while (i < sub.length && IS(sub.str[i], IS_DIGIT))
	{
		n = n * 10 + sub.str[i] - '0';
		i++;
	}
	*dst = n;
	return (i);
}

uint32_t		ft_subto_float(t_sub sub, float *dst)
{
	uint32_t		i;
	uint32_t		tmp;
	float			f;
	bool			neg;

	neg = BOOL_OF(sub.length > 0 && sub.str[0] == '-');
	i = neg ? 1 : 0;
	f = 0.f;
	while (i < sub.length && IS(sub.str[i], IS_DIGIT))
		f = f * 10.f + (float)(sub.str[i++] - '0');
	*dst = f;
	if (i < sub.length && sub.str[i] == '.')
	{
		while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
			;
		tmp = i;
		f = 0.f;
		while (sub.str[--tmp] != '.')
			f = (f + (float)(sub.str[tmp] - '0')) / 10.f;
		*dst += f;
	}
	if (neg)
		*dst = -(*dst);
	return (i);
}
