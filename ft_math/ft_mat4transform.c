/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:39:00 by juloo             #+#    #+#             */
/*   Updated: 2016/05/09 16:43:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"
#include "ft/math_vec3.h"

t_mat4			ft_mat4transform(t_vec3 pos, t_vec3 rot,
					t_vec3 shear, t_vec3 scale)
{
	t_mat4			m;

	m = MAT4_I();
	ft_mat4translate(&m, pos);
	ft_mat4shear(&m, shear);
	ft_mat4rotate(&m, rot);
	ft_mat4scale3(&m, scale);
	return (m);
}

t_mat4			ft_mat4transform_inv(t_vec3 pos, t_vec3 rot,
					t_vec3 shear, t_vec3 scale)
{
	t_mat4			m;

	m = MAT4_I();
	ft_mat4scale3(&m, VEC3_DIV(VEC3_1(1.f), scale));
	ft_mat4rotate_inv(&m, rot);
	ft_mat4shear(&m, VEC3_SUB(VEC3_0(), shear));
	ft_mat4translate(&m, VEC3_SUB(VEC3_0(), pos));
	return (m);
}
