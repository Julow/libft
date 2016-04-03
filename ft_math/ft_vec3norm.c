/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:12:45 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/30 10:46:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec3.h"
#include <math.h>

t_vec3			ft_vec3norm(t_vec3 v)
{
	float			tmp;

	tmp = VEC3_DOT(v, v);
	if (tmp == 0.f)
		return (VEC3_UP());
	if (tmp > 0.99999f && tmp < 1.00001)
		return (v);
	tmp = sqrtf(tmp);
	return (VEC3_DIV1(v, tmp));
}
