/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 17:31:13 by juloo             #+#    #+#             */
/*   Updated: 2015/08/23 12:17:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_mdr
{
	float			n;
	char			c;
}				t_mdr;

static void		test_it(t_deque *v)
{
	t_deque_it		it;
	t_mdr			*f;

	it = DEQUE_IT(v);
	if ((f = DEQUE_NEXT(it)))
		printf("[ %f", f->n);
	while ((f = DEQUE_NEXT(it)))
	{
		printf(", %f", f->n);
	}
	printf(" ]\n");
}

static void		test_chunks(t_deque *v)
{
	int				total_len;
	int				len;
	t_que_c			*c;

	total_len = 0;
	c = v->first;
	printf("chunks:");
	while (c != NULL)
	{
		len = (c->end - c->start) / v->element_size;
		total_len += len;
		printf(" [%d - %d]", c->start, c->end);
		c = c->next;
	}
	printf("\n");
}

static void		test_push_back(t_deque *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		tmp = (t_mdr){(float)ft_rand(0, 100), 'a'};
		ft_qpush_back(v, &tmp);
		// test_chunks(v);
		// test_it(v);
	}
}

static void		test_push_front(t_deque *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		tmp = (t_mdr){(float)ft_rand(0, 100), 'a'};
		ft_qpush_front(v, &tmp);
		test_chunks(v);
		// test_it(v);
	}
}

static void		test_pop_back(t_deque *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		ft_qpop_back(v, &tmp);
		test_chunks(v);
		// test_it(v);
	}
}

static void		test_remove(t_deque *v, float max)
{
	t_deque_it		it;
	t_mdr			*mdr;

	it = DEQUE_IT(v);
	while ((mdr = DEQUE_NEXT(it)))
	{
		if (mdr->n < max)
		{
			printf("remove %f\n", mdr->n);
			ft_qremove(&it);
		}
	}
	it = DEQUE_IT(v);
	while ((mdr = DEQUE_NEXT(it)))
	{
		if (mdr->n < max)
		{
			printf("error %f found\n", mdr->n);
		}
	}
}

static void		test_pop_front(t_deque *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		ft_qpop_front(v, &tmp);
		test_chunks(v);
		// test_it(v);
	}
}

int				main(void)
{
	t_deque		v;

	srand(ft_clock(0));
	v = DEQUE(t_mdr);
	printf("sizeof(t_mdr): %d; size: %d\n", (int)sizeof(t_mdr), v.element_size);
	test_push_back(&v, 150);
	test_chunks(&v);
	test_it(&v);
	test_pop_back(&v, 55);
	test_it(&v);
	test_push_front(&v, 30);
	test_it(&v);
	test_remove(&v, 50);
	test_it(&v);
	test_pop_front(&v, v.length);
	test_it(&v);
	ft_qclear(&v);
	return (0);
}
