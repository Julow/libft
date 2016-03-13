/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:45:54 by juloo             #+#    #+#             */
/*   Updated: 2016/03/13 22:55:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"

void			ft_mat4apply_vec4(t_mat4 const *m, t_vec4 *v)
{
	t_vec4 const	tmp = *v;

	v->x = VEC4_DOT(m->x, tmp);
	v->y = VEC4_DOT(m->y, tmp);
	v->z = VEC4_DOT(m->z, tmp);
	v->w = VEC4_DOT(m->w, tmp);
}

void			ft_mat4apply_vec3(t_mat4 const *m, t_vec3 *v, float w)
{
	t_vec3 const	tmp = *v;

	v->x = VEC3_DOT(m->x, tmp) + m->x.w * w;
	v->y = VEC3_DOT(m->y, tmp) + m->y.w * w;
	v->z = VEC3_DOT(m->z, tmp) + m->z.w * w;
}
