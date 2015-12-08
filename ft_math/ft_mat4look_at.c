/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4look_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:01:12 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 16:59:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

t_mat4			ft_mat4look_at(t_vec3 pos, t_vec3 target, t_vec3 up)
{
	t_vec3 const	z_a = ft_vec3norm(ft_vec3sub(target, pos));
	t_vec3 const	x_a = ft_vec3norm(ft_vec3cross(up, z_a));
	t_vec3 const	y_a = ft_vec3cross(z_a, x_a);

	return ((t_mat4){
		{x_a.x, x_a.y, x_a.z, -ft_vec3dot(x_a, pos)},
		{y_a.x, y_a.y, y_a.z, -ft_vec3dot(y_a, pos)},
		{z_a.x, z_a.y, z_a.z, -ft_vec3dot(z_a, pos)},
		{0.f, 0.f, 0.f, 1.f}
	});
}
