/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"

void			*ft_vpush_back(t_vector *v, void *data, int count)
{
	void			*start;

	if ((v->length + count) > v->capacity)
		ft_vreserve(v, count);
	start = v->data + (v->length * v->element_size);
	v->length += count;
	if (data == NULL)
		ft_bzero(start, count * v->element_size);
	else
		ft_memcpy(start, data, count * v->element_size);
	return (start);
}
