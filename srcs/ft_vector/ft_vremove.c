/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 12:52:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void			ft_vremove(t_vector *v, int index, int count)
{
	if (index < 0)
		index += v->length;
	if (count < 0)
		count += v->length - index;
	v->length -= count;
	index *= v->element_size;
	count *= v->element_size;
	count += index;
	ft_memmove(v->data + index, v->data + count, v->length * v->element_size - count);
}
