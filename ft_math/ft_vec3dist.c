/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:41:11 by juloo             #+#    #+#             */
/*   Updated: 2016/03/13 22:56:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec3.h"
#include <math.h>

float			ft_vec3length(t_vec3 v)
{
	return (sqrtf(VEC3_DOT(v, v)));
}

float			ft_vec3dist(t_vec3 a, t_vec3 b)
{
	a = VEC3_SUB(a, b);
	return (sqrtf(VEC3_DOT(a, a)));
}

float			ft_vec3dist2(t_vec3 a, t_vec3 b)
{
	a = VEC3_SUB(a, b);
	return (VEC3_DOT(a, a));
}
