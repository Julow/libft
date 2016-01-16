/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:34 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/16 19:18:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"

void			*ft_vpush(t_vector *v, void *data, uint32_t count)
{
	void			*start;

	if ((v->length + count) > v->capacity)
		ft_vreserve(v, MAX(v->capacity, VECTOR_MIN_CAP) * 2);
	start = v->data + (v->length * v->element_size);
	v->length += count;
	if (data != NULL)
		ft_memcpy(start, data, count * v->element_size);
	return (start);
}
