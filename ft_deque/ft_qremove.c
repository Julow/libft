/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 20:46:06 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:18:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_deque.h"
#include "ft/libft.h"

void			ft_qremove(t_deque_it *it)
{
	t_que_c			*c;

	c = (it->next == NULL) ? it->deque->last : it->next->prev;
	memmove(it->data, it->data + it->deque->element_size,
		(int)(it->end - it->data));
	it->deque->length--;
	c->end -= it->deque->element_size;
	if (c->start >= c->end)
	{
		deque_c_del(it->deque, c);
		it->end = NULL;
	}
	else
		it->end -= it->deque->element_size;
	it->data -= it->deque->element_size;
}
