/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 20:55:33 by juloo             #+#    #+#             */
/*   Updated: 2016/05/12 23:40:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat3.h"

void			ft_mat3apply(t_mat3 const *m, t_vec3 *v)
{
	t_vec3 const	tmp = *v;

	v->x = VEC3_DOT(m->x, tmp);
	v->y = VEC3_DOT(m->y, tmp);
	v->z = VEC3_DOT(m->z, tmp);
}
