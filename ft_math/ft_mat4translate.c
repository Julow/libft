/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 12:56:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 16:59:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

void			ft_mat4translate(t_mat4 *m_a, t_vec3 t)
{
	t_mat4 const	a = *m_a;

	m_a->x.w = a.x.x * t.x + a.x.y * t.y + a.x.z * t.z + a.x.w;
	m_a->y.w = a.y.x * t.x + a.y.y * t.y + a.y.z * t.z + a.y.w;
	m_a->z.w = a.z.x * t.x + a.z.y * t.y + a.z.z * t.z + a.z.w;
	m_a->w.w = a.w.x * t.x + a.w.y * t.y + a.w.z * t.z + a.w.w;
}
