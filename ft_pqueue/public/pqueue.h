/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pqueue.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 21:39:36 by juloo             #+#    #+#             */
/*   Updated: 2016/06/02 23:08:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PQUEUE_H
# define PQUEUE_H

# include "ft/ft_vector.h"
# include "ft/libft.h"

typedef struct s_pqueue		t_pqueue;

/*
** ========================================================================== **
** Priority queue
*/

struct			s_pqueue
{
	t_vector		heap;
	t_vector		data;
	int				(*cmp)(void const*, void const*);
	uint32_t		freed;
};

# define PQUEUE(T, CMP)	((t_pqueue){VECTOR(uint32_t), VECTOR(T), V(CMP), 0})

/*
** Reference to the top element
** Should not be used on an empty pqueue
** 'Q' is used several times
*/
# define PQUEUE_PEEK(Q)	((void const*)VECTOR_GET((Q).data, _PQUEUE_PEEK(Q)))

/*
** Push 'data' into the pqueue
*/
void			ft_ppush(t_pqueue *q, void const *data);

/*
** Extract the top element
** Copy it's data into 'dst' if it is not NULL
** Return false on empty queue, true otherwise
*/
bool			ft_ppop(t_pqueue *q, void *dst);

/*
** -
*/

# define _PQUEUE_PEEK(Q)	(*(uint32_t const*)((Q).heap.data))

#endif
