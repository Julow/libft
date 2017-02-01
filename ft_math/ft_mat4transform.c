/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:39:00 by juloo             #+#    #+#             */
/*   Updated: 2017/02/01 19:13:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"
#include "ft/math_vec3.h"

#include <math.h>

void			ft_mat4transform(t_vec3 const *pos, t_vec3 const *rot,
					t_vec3 const *scale, t_mat4 *dst)
{
	t_vec3 const	c = VEC3(cosf(rot->x), cosf(rot->y), cosf(rot->z));
	t_vec3 const	s = VEC3(sinf(rot->x), sinf(rot->y), sinf(rot->z));

	dst->x.x = scale->x * c.z * c.y;
	dst->x.y = scale->y * (c.z * s.x * s.y - c.x * s.z);
	dst->x.z = scale->z * (c.x * c.z * s.y + s.x * s.z);
	dst->x.w = pos->x;
	dst->y.x = scale->x * s.z * c.y;
	dst->y.y = scale->y * (s.x * s.y * s.z + c.x * c.z);
	dst->y.z = scale->z * (c.x * s.y * s.z - c.z * s.x);
	dst->y.w = pos->y;
	dst->z.x = -scale->x * s.y;
	dst->z.y = scale->y * s.x * c.y;
	dst->z.z = scale->z * c.x * c.y;
	dst->z.w = pos->z;
	dst->w = VEC4(0.f, 0.f, 0.f, 1.f);
}

void			ft_mat4transform_inv(t_vec3 const *pos, t_vec3 const *rot,
					t_vec3 const *scale, t_mat4 *dst)
{
	t_vec3 const	c = VEC3(cosf(-rot->x), cosf(-rot->y), cosf(-rot->z));
	t_vec3 const	s = VEC3(sinf(-rot->x), sinf(-rot->y), sinf(-rot->z));

	dst->x.x = c.z * c.y / scale->x;
	dst->x.y = -s.z * c.y / scale->x;
	dst->x.z = s.y / scale->x;
	dst->x.w = -dst->x.x * pos->x - dst->x.y * pos->y - dst->x.z * pos->z;
	dst->y.x = (c.z * s.x * s.y + c.x * s.z) / scale->y;
	dst->y.y = (c.x * c.z - s.x * s.y * s.z) / scale->y;
	dst->y.z = -s.x * c.y / scale->y;
	dst->y.w = -dst->y.x * pos->x - dst->y.y * pos->y - dst->y.z * pos->z;
	dst->z.x = (s.x * s.z - c.x * c.z * s.y) / scale->z;
	dst->z.y = (c.z * s.x + c.x * s.y * s.z) / scale->z;
	dst->z.z = c.x * c.y / scale->z;
	dst->z.w = -dst->z.x * pos->x - dst->z.y * pos->y - dst->z.z * pos->z;
	dst->w = VEC4(0.f, 0.f, 0.f, 1.f);
}
