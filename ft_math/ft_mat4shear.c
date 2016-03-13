/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4shear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 10:23:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/13 22:36:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"

void			ft_mat4shear(t_mat4 *mat, t_vec3 shear)
{
	t_mat4 const	a = *mat;

	mat->x.x = a.x.x + a.x.y * shear.y + a.x.z * shear.z;
	mat->x.y = a.x.x * shear.x + a.x.y + a.x.z * shear.z;
	mat->x.z = a.x.x * shear.x + a.x.y * shear.y + a.x.z;
	mat->y.x = a.y.x + a.y.y * shear.y + a.y.z * shear.z;
	mat->y.y = a.y.x * shear.x + a.y.y + a.y.z * shear.z;
	mat->y.z = a.y.x * shear.x + a.y.y * shear.y + a.y.z;
	mat->z.x = a.z.x + a.z.y * shear.y + a.z.z * shear.z;
	mat->z.y = a.z.x * shear.x + a.z.y + a.z.z * shear.z;
	mat->z.z = a.z.x * shear.x + a.z.y * shear.y + a.z.z;
	mat->w.x = a.w.x + a.w.y * shear.y + a.w.z * shear.z;
	mat->w.y = a.w.x * shear.x + a.w.y + a.w.z * shear.z;
	mat->w.z = a.w.x * shear.x + a.w.y * shear.y + a.w.z;
}
