/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 19:26:05 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 19:31:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

void			*ft_vpush_front(t_vector *v, void *data)
{
	void			*dst;

	if (v->first == NULL || v->first->start < v->element_size)
		vector_c_before(v, v->first);
	v->first->start -= v->element_size;
	dst = VEC_C_DATA(v->first) + v->first->start;
	v->length++;
	if (data == NULL)
		ft_bzero(dst, v->element_size);
	else
		ft_memcpy(dst, data, v->element_size);
	return (dst);
}
