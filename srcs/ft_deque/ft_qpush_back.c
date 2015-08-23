/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 16:38:02 by juloo             #+#    #+#             */
/*   Updated: 2015/08/23 12:15:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_deque.h"

void			*ft_qpush_back(t_deque *v, void *data)
{
	void			*dst;

	if (v->last == NULL || (v->last->end + v->element_size) > QUE_C_SIZE)
		deque_c_after(v, v->last);
	dst = QUE_C_DATA(v->last) + v->last->end;
	v->last->end += v->element_size;
	v->length++;
	if (data == NULL)
		ft_bzero(dst, v->element_size);
	else
		ft_memcpy(dst, data, v->element_size);
	return (dst);
}
