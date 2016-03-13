/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:57:48 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/13 22:36:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"
#include <math.h>

static void		ft_mat4rotate_x(t_mat4 *m_a, float x)
{
	t_mat4 const	a = *m_a;
	float const		cos_x = cosf(x);
	float const		sin_x = sinf(x);

	m_a->x.y = a.x.y * cos_x + a.x.z * sin_x;
	m_a->x.z = a.x.y * -sin_x + a.x.z * cos_x;
	m_a->y.y = a.y.y * cos_x + a.y.z * sin_x;
	m_a->y.z = a.y.y * -sin_x + a.y.z * cos_x;
	m_a->z.y = a.z.y * cos_x + a.z.z * sin_x;
	m_a->z.z = a.z.y * -sin_x + a.z.z * cos_x;
	m_a->w.y = a.w.y * cos_x + a.w.z * sin_x;
	m_a->w.z = a.w.y * -sin_x + a.w.z * cos_x;
}

static void		ft_mat4rotate_y(t_mat4 *m_a, float y)
{
	t_mat4 const	a = *m_a;
	float const		cos_y = cosf(y);
	float const		sin_y = sinf(y);

	m_a->x.x = a.x.x * cos_y + a.x.z * -sin_y;
	m_a->x.z = a.x.x * sin_y + a.x.z * cos_y;
	m_a->y.x = a.y.x * cos_y + a.y.z * -sin_y;
	m_a->y.z = a.y.x * sin_y + a.y.z * cos_y;
	m_a->z.x = a.z.x * cos_y + a.z.z * -sin_y;
	m_a->z.z = a.z.x * sin_y + a.z.z * cos_y;
	m_a->w.x = a.w.x * cos_y + a.w.z * -sin_y;
	m_a->w.z = a.w.x * sin_y + a.w.z * cos_y;
}

static void		ft_mat4rotate_z(t_mat4 *m_a, float z)
{
	t_mat4 const	a = *m_a;
	float const		cos_z = cosf(z);
	float const		sin_z = sinf(z);

	m_a->x.x = a.x.x * cos_z + a.x.y * sin_z;
	m_a->x.y = a.x.x * -sin_z + a.x.y * cos_z;
	m_a->y.x = a.y.x * cos_z + a.y.y * sin_z;
	m_a->y.y = a.y.x * -sin_z + a.y.y * cos_z;
	m_a->z.x = a.z.x * cos_z + a.z.y * sin_z;
	m_a->z.y = a.z.x * -sin_z + a.z.y * cos_z;
	m_a->w.x = a.w.x * cos_z + a.w.y * sin_z;
	m_a->w.y = a.w.x * -sin_z + a.w.y * cos_z;
}

void			ft_mat4rotate(t_mat4 *mat, t_vec3 rotate)
{
	ft_mat4rotate_z(mat, rotate.z);
	ft_mat4rotate_y(mat, rotate.y);
	ft_mat4rotate_x(mat, rotate.x);
}

void			ft_mat4rotate_inv(t_mat4 *mat, t_vec3 rotate)
{
	ft_mat4rotate_x(mat, 0.f - rotate.x);
	ft_mat4rotate_y(mat, 0.f - rotate.y);
	ft_mat4rotate_z(mat, 0.f - rotate.z);
}
