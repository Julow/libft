/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 21:49:30 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:15:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/pqueue.h"

static uint32_t	push_data(t_pqueue *q, void const *data)
{
	uint32_t		index;

	if (q->freed < q->data.length)
	{
		index = q->freed;
		q->freed = *(uint32_t const*)VECTOR_GET(q->data, q->freed);
	}
	else
	{
		index = q->data.length;
		ft_vpush(&q->data, NULL, 1);
		q->freed = q->data.length;
	}
	memcpy(VECTOR_GET(q->data, index), data, q->data.element_size);
	return (index);
}

static void		push_heap(t_pqueue *q, uint32_t data_index)
{
	uint32_t		i;
	uint32_t		parent;
	uint32_t		tmp;
	uint32_t		*heap;

	i = q->heap.length;
	ft_vpush(&q->heap, &data_index, 1);
	heap = q->heap.data;
	while (i > 0)
	{
		parent = (i - 1) / 2;
		if (q->cmp(VECTOR_GET(q->data, heap[i]),
				VECTOR_GET(q->data, heap[parent])) >= 0)
			break ;
		tmp = heap[parent];
		heap[parent] = heap[i];
		heap[i] = tmp;
		i = parent;
	}
}

void			ft_ppush(t_pqueue *q, void const *data)
{
	push_heap(q, push_data(q, data));
}
