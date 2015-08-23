/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:30:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 15:25:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void			ft_vremove(t_vector *v, int index, int count)
{
	int				to;

	if (index < 0)
		index += v->length;
	if (count < 0)
		count += v->length - index;
	index *= v->element_size;
	to = count * v->element_size + index;
	ft_memmove(v->data + index, v->data + to, v->length * v->element_size - to);
	v->length -= count;
}
