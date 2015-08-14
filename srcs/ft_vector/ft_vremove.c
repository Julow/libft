/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 20:46:06 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 22:21:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

void			ft_vremove(t_vector_it *it)
{
	t_vec_c			*c;

	c = (it->next == NULL) ? it->vector->last : it->next->prev;
	ft_memmove(it->data, it->data + it->vector->element_size,
		(int)(it->end - it->data));
	it->vector->length--;
	c->end -= it->vector->element_size;
	if (c->start >= c->end)
	{
		vector_c_del(it->vector, c);
		it->end = NULL;
	}
	else
		it->end -= it->vector->element_size;
	it->data -= it->vector->element_size;
}
