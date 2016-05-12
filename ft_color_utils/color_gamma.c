/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gamma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:02:23 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 23:46:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"
#include <math.h>

uint32_t		color32_gamma(uint32_t color, float gamma)
{
	t_vec3			tmp;

	tmp = COLOR_24TOF(color);
	tmp = VEC3(powf(tmp.x, gamma), powf(tmp.y, gamma), powf(tmp.z, gamma));
	tmp = VEC3_MIN(tmp, VEC3_1(1.f));
	return (COLOR_FTO24(tmp) | (color & COLOR32_A_MASK));
}

t_vec3			colorf_gamma(t_vec3 c, float gamma)
{
	return (VEC3(powf(c.x, gamma), powf(c.y, gamma), powf(c.z, gamma)));
}
