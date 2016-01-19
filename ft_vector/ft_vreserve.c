/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vreserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:22 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/19 16:11:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"
#include <stdlib.h>

void			ft_vreserve(t_vector *v, uint32_t capacity)
{
	void			*tmp;

	if (capacity < v->length)
		capacity = v->length;
	if (capacity == v->capacity)
		return ;
	tmp = MALLOC(capacity * v->element_size);
	ft_memcpy(tmp, v->data, v->length * v->element_size);
	if (v->capacity > 0)
		free(v->data);
	v->data = tmp;
	v->capacity = capacity;
}
