/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:57:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 16:59:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

void			ft_mat4scale(t_mat4 *m_a, float scale)
{
	if (scale == 1.f)
		return ;
	m_a->x.x *= scale;
	m_a->x.y *= scale;
	m_a->x.z *= scale;
	m_a->y.x *= scale;
	m_a->y.y *= scale;
	m_a->y.z *= scale;
	m_a->z.x *= scale;
	m_a->z.y *= scale;
	m_a->z.z *= scale;
	m_a->w.x *= scale;
	m_a->w.y *= scale;
	m_a->w.z *= scale;
}

void			ft_mat4scale3(t_mat4 *m_a, t_vec3 scale)
{
	m_a->x.x *= scale.x;
	m_a->x.y *= scale.y;
	m_a->x.z *= scale.z;
	m_a->y.x *= scale.x;
	m_a->y.y *= scale.y;
	m_a->y.z *= scale.z;
	m_a->z.x *= scale.x;
	m_a->z.y *= scale.y;
	m_a->z.z *= scale.z;
	m_a->w.x *= scale.x;
	m_a->w.y *= scale.y;
	m_a->w.z *= scale.z;
}
