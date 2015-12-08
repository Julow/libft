/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 09:21:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 16:59:51 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

void			ft_mat4reflect(t_mat4 *mat, int flags)
{
	float const		reflect_x = (flags & REFLECT_X) ? -1.f : 1.f;
	float const		reflect_y = (flags & REFLECT_Y) ? -1.f : 1.f;
	float const		reflect_z = (flags & REFLECT_Z) ? -1.f : 1.f;

	if (!(flags & (REFLECT_X | REFLECT_Y | REFLECT_Z)))
		return ;
	mat->x.x *= reflect_x;
	mat->x.y *= reflect_y;
	mat->x.z *= reflect_z;
	mat->y.x *= reflect_x;
	mat->y.y *= reflect_y;
	mat->y.z *= reflect_z;
	mat->z.x *= reflect_x;
	mat->z.y *= reflect_y;
	mat->z.z *= reflect_z;
	mat->w.x *= reflect_x;
	mat->w.y *= reflect_y;
	mat->w.z *= reflect_z;
}

void			ft_mat4reflect_inv(t_mat4 *mat, int flags)
{
	int				inv_flags;

	inv_flags = 0;
	if (flags & REFLECT_X)
		inv_flags |= REFLECT_Y | REFLECT_Z;
	if (flags & REFLECT_Y)
		inv_flags |= REFLECT_X | REFLECT_Z;
	if (flags & REFLECT_Z)
		inv_flags |= REFLECT_X | REFLECT_Y;
	ft_mat4reflect(mat, inv_flags);
}
