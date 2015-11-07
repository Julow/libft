/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 19:26:05 by juloo             #+#    #+#             */
/*   Updated: 2015/08/23 12:15:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_deque.h"

void			*ft_qpush_front(t_deque *v, void *data)
{
	void			*dst;

	if (v->first == NULL || v->first->start < v->element_size)
		deque_c_before(v, v->first);
	v->first->start -= v->element_size;
	dst = QUE_C_DATA(v->first) + v->first->start;
	v->length++;
	if (data == NULL)
		ft_bzero(dst, v->element_size);
	else
		ft_memcpy(dst, data, v->element_size);
	return (dst);
}
