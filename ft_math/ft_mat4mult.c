/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 13:04:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 16:59:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

t_mat4			*ft_mat4mult(t_mat4 const *a, t_mat4 const *b, t_mat4 *dst)
{
	t_vec4			ta;

	ta = a->x;
	dst->x.x = ta.x * b->x.x + ta.y * b->y.x + ta.z * b->z.x + ta.w * b->w.x;
	dst->x.y = ta.x * b->x.y + ta.y * b->y.y + ta.z * b->z.y + ta.w * b->w.y;
	dst->x.z = ta.x * b->x.z + ta.y * b->y.z + ta.z * b->z.z + ta.w * b->w.z;
	dst->x.w = ta.x * b->x.w + ta.y * b->y.w + ta.z * b->z.w + ta.w * b->w.w;
	ta = a->y;
	dst->y.x = ta.x * b->x.x + ta.y * b->y.x + ta.z * b->z.x + ta.w * b->w.x;
	dst->y.y = ta.x * b->x.y + ta.y * b->y.y + ta.z * b->z.y + ta.w * b->w.y;
	dst->y.z = ta.x * b->x.z + ta.y * b->y.z + ta.z * b->z.z + ta.w * b->w.z;
	dst->y.w = ta.x * b->x.w + ta.y * b->y.w + ta.z * b->z.w + ta.w * b->w.w;
	ta = a->z;
	dst->z.x = ta.x * b->x.x + ta.y * b->y.x + ta.z * b->z.x + ta.w * b->w.x;
	dst->z.y = ta.x * b->x.y + ta.y * b->y.y + ta.z * b->z.y + ta.w * b->w.y;
	dst->z.z = ta.x * b->x.z + ta.y * b->y.z + ta.z * b->z.z + ta.w * b->w.z;
	dst->z.w = ta.x * b->x.w + ta.y * b->y.w + ta.z * b->z.w + ta.w * b->w.w;
	ta = a->w;
	dst->w.x = ta.x * b->x.x + ta.y * b->y.x + ta.z * b->z.x + ta.w * b->w.x;
	dst->w.y = ta.x * b->x.y + ta.y * b->y.y + ta.z * b->z.y + ta.w * b->w.y;
	dst->w.z = ta.x * b->x.z + ta.y * b->y.z + ta.z * b->z.z + ta.w * b->w.z;
	dst->w.w = ta.x * b->x.w + ta.y * b->y.w + ta.z * b->z.w + ta.w * b->w.w;
	return (dst);
}
