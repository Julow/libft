/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 19:59:06 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"
#include "ft/ft_deque.h"

void			ft_qpop_front(t_deque *v, void *data)
{
	if (v->first == NULL)
		return ;
	if (data != NULL)
		ft_memcpy(data, QUE_C_DATA(v->first) + v->first->start,
			v->element_size);
	v->first->start += v->element_size;
	v->length--;
	if (v->first->start >= v->first->end)
		deque_c_del(v, v->first);
}
