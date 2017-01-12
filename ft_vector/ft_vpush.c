/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:34 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 12:13:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"

void			*ft_vpush(t_vector *v, void const *data, uint32_t count)
{
	void			*start;

	while ((v->length + count) > v->capacity)
		ft_vreserve(v, MAX(v->capacity * 2, VECTOR_MIN_CAP));
	start = v->data + (v->length * v->element_size);
	v->length += count;
	if (data != NULL)
		memcpy(start, data, count * v->element_size);
	return (start);
}
