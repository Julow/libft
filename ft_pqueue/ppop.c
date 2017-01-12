/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:34:32 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:15:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/pqueue.h"

static void		heapify(t_pqueue *q)
{
	uint32_t *const	heap = q->heap.data;
	uint32_t		next;
	uint32_t		tmp;
	uint32_t		i;

	heap[0] = heap[q->heap.length];
	i = 0;
	next = 0;
	while (true)
	{
		if ((tmp = i * 2 + 1) < q->heap.length
			&& q->cmp(VECTOR_GET(q->data, heap[tmp]),
					VECTOR_GET(q->data, heap[next])) < 0)
			next = tmp;
		if ((tmp = i * 2 + 2) < q->heap.length
			&& q->cmp(VECTOR_GET(q->data, heap[tmp]),
					VECTOR_GET(q->data, heap[next])) < 0)
			next = tmp;
		if (next == i)
			break ;
		tmp = heap[i];
		heap[i] = heap[next];
		heap[next] = tmp;
		i = next;
	}
}

bool			ft_ppop(t_pqueue *q, void *dst)
{
	uint32_t const	top = *(uint32_t const*)q->heap.data;

	if (q->heap.length == 0)
		return (false);
	if (dst != NULL)
		memcpy(dst, VECTOR_GET(q->data, top), q->data.element_size);
	*(uint32_t*)VECTOR_GET(q->data, top) = q->freed;
	q->freed = top;
	q->heap.length--;
	if (q->heap.length > 0)
		heapify(q);
	return (true);
}
