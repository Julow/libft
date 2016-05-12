/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 20:40:47 by juloo             #+#    #+#             */
/*   Updated: 2016/05/12 23:40:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat3.h"

void			ft_mat3mul(t_mat3 *dst, t_mat3 const *a, t_mat3 const *b)
{
	t_vec3			tmp;

	tmp = a->x;
	dst->x.x = tmp.x * b->x.x + tmp.y * b->y.x + tmp.z * b->z.x;
	dst->x.y = tmp.x * b->x.y + tmp.y * b->y.y + tmp.z * b->z.y;
	dst->x.z = tmp.x * b->x.z + tmp.y * b->y.z + tmp.z * b->z.z;
	tmp = a->y;
	dst->y.x = tmp.x * b->x.x + tmp.y * b->y.x + tmp.z * b->z.x;
	dst->y.y = tmp.x * b->x.y + tmp.y * b->y.y + tmp.z * b->z.y;
	dst->y.z = tmp.x * b->x.z + tmp.y * b->y.z + tmp.z * b->z.z;
	tmp = a->z;
	dst->z.x = tmp.x * b->x.x + tmp.y * b->y.x + tmp.z * b->z.x;
	dst->z.y = tmp.x * b->x.y + tmp.y * b->y.y + tmp.z * b->z.y;
	dst->z.z = tmp.x * b->x.z + tmp.y * b->y.z + tmp.z * b->z.z;
}
