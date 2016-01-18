/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:30 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/18 18:20:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"

void			ft_vremove(t_vector *v, int32_t index, int32_t count)
{
	uint32_t		to;

	if (index < 0)
		index += v->length + 1;
	if (count < 0)
	{
		index += count;
		count = -count;
	}
	to = index + count;
	if (v->length > to)
		ft_memmove(v->data + (index * v->element_size),
			v->data + (to * v->element_size),
			(v->length - to) * v->element_size);
	v->length -= count;
}
