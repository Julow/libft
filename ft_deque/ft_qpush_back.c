/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 16:38:02 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:20:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_deque.h"
#include "ft/libft.h"

void			*ft_qpush_back(t_deque *v, void *data)
{
	void			*dst;

	if (v->last == NULL || (v->last->end + v->element_size) > QUE_C_SIZE)
		deque_c_after(v, v->last);
	dst = QUE_C_DATA(v->last) + v->last->end;
	v->last->end += v->element_size;
	v->length++;
	if (data == NULL)
		memset(dst, 0, v->element_size);
	else
		memcpy(dst, data, v->element_size);
	return (dst);
}
