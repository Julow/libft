/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 16:52:55 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/13 22:35:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec3.h"
#include <math.h>

static void		ft_vec3rotate_x(t_vec3 *v_a, float x)
{
	t_vec3 const	a = *v_a;
	float const		cos_x = cosf(x);
	float const		sin_x = sinf(x);

	v_a->y = a.y * cos_x + a.z * sin_x;
	v_a->z = a.y * -sin_x + a.z * cos_x;
}

static void		ft_vec3rotate_y(t_vec3 *v_a, float y)
{
	t_vec3 const	a = *v_a;
	float const		cos_y = cosf(y);
	float const		sin_y = sinf(y);

	v_a->x = a.x * cos_y + a.z * -sin_y;
	v_a->z = a.x * sin_y + a.z * cos_y;
}

static void		ft_vec3rotate_z(t_vec3 *v_a, float z)
{
	t_vec3 const	a = *v_a;
	float const		cos_z = cosf(z);
	float const		sin_z = sinf(z);

	v_a->x = a.x * cos_z + a.y * sin_z;
	v_a->y = a.x * -sin_z + a.y * cos_z;
}

void			ft_vec3rotate(t_vec3 *v, t_vec3 rotate)
{
	ft_vec3rotate_z(v, rotate.z);
	ft_vec3rotate_y(v, rotate.y);
	ft_vec3rotate_x(v, rotate.x);
}
