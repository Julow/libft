/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vspan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 22:27:12 by juloo             #+#    #+#             */
/*   Updated: 2016/02/02 00:35:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"

void		*ft_vspan(t_vector *v, t_vec2u span, void const *data, uint32_t n)
{
	int32_t		move;

	move = ((int32_t)n) - ((int32_t)(span.y - span.x));
	while ((v->length + move) > v->capacity)
		ft_vreserve(v, MAX(v->capacity * 2, VECTOR_MIN_CAP));
	if (move != 0)
	{
		if (v->length > span.y)
			ft_memmove(VECTOR_GET(*v, span.y + move), VECTOR_GET(*v, span.y),
				VECTOR_OFF(*v, v->length - span.y));
		v->length += move;
	}
	if (data != NULL)
		ft_memcpy(VECTOR_GET(*v, span.x), data, VECTOR_OFF(*v, n));
	return (VECTOR_GET(*v, span.x));
}
