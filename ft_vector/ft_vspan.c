/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vspan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 22:27:12 by juloo             #+#    #+#             */
/*   Updated: 2016/02/01 23:04:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"

void		*ft_vspan(t_vector *v, t_vec2u span, void const *data, uint32_t n)
{
	void		*start;

	while ((v->length + n + span.x - span.y) > v->capacity)
		ft_vreserve(v, MAX(v->capacity * 2, VECTOR_MIN_CAP));
	span.x *= v->element_size;
	span.y *= v->element_size;
	n *= v->element_size;
	start = v->data + span.x;
	if ((span.y - span.x) != n)
		ft_memmove(start + n, v->data + span.y,
			v->length * v->element_size - span.y);
	if (data != NULL)
		ft_memcpy(start, data, n);
	return (start);
}
