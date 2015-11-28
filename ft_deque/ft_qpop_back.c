/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 18:30:33 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"
#include "ft/ft_deque.h"

void			ft_qpop_back(t_deque *v, void *data)
{
	if (v->last == NULL)
		return ;
	v->last->end -= v->element_size;
	v->length--;
	if (data != NULL)
		ft_memcpy(data, QUE_C_DATA(v->last) + v->last->end, v->element_size);
	if (v->last->start >= v->last->end)
		deque_c_del(v, v->last);
}
