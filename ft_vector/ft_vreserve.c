/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vreserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"
#include <stdlib.h>

void			ft_vreserve(t_vector *v, int count)
{
	int				capacity;
	void			*data;

	capacity = MAX(v->capacity, VECTOR_MIN_CAP);
	while ((v->length + count) > capacity)
		capacity *= 2;
	if (capacity == v->capacity)
		return ;
	data = ft_emalloc(capacity * v->element_size);
	if (v->data != NULL)
	{
		ft_memcpy(data, v->data, v->length * v->element_size);
		free(v->data);
	}
	v->data = data;
	v->capacity = capacity;
}
