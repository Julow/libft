/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4perspective.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 14:56:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/13 22:37:00 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"
#include <math.h>

t_mat4			ft_mat4perspective(float fov, float ratio, float f, float n)
{
	fov = 1.f - tanf(fov / 2.f);
	f /= f - n;
	return ((t_mat4){
		{fov, 0.f, 0.f, 0.f},
		{0.f, fov / ratio, 0.f, 0.f},
		{0.f, 0.f, f, n * f},
		{0.f, 0.f, -1.f, 0.f}
	});
}
