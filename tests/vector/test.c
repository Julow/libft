/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 17:31:13 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 20:35:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_mdr
{
	float			n;
	char			c;
}				t_mdr;

static void		test_it(t_vector *v)
{
	t_vector_it		it;
	t_mdr			*f;

	it = VECTOR_IT(v);
	if ((f = VECTOR_NEXT(it)))
		printf("[ %f", f->n);
	while ((f = VECTOR_NEXT(it)))
	{
		printf(", %f", f->n);
	}
	printf(" ]\n");
}

static void		test_chunks(t_vector *v)
{
	int				total_len;
	int				len;
	t_vec_c			*c;

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

static void		test_push_back(t_vector *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		tmp = (t_mdr){(float)ft_rand(0, 100), 'a'};
		ft_vpush_back(v, &tmp);
		// test_chunks(v);
		// test_it(v);
	}
}

static void		test_push_front(t_vector *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		tmp = (t_mdr){(float)ft_rand(0, 100), 'a'};
		ft_vpush_front(v, &tmp);
		test_chunks(v);
		// test_it(v);
	}
}

static void		test_pop_back(t_vector *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		ft_vpop_back(v, &tmp);
		test_chunks(v);
		// test_it(v);
	}
}

static void		test_pop_front(t_vector *v, int count)
{
	t_mdr			tmp;

	while (--count >= 0)
	{
		ft_vpop_front(v, &tmp);
		test_chunks(v);
		// test_it(v);
	}
}

int				main(void)
{
	t_vector		v;

	srand(ft_clock(0));
	v = VECTOR(t_mdr);
	printf("sizeof(t_mdr): %d; size: %d\n", (int)sizeof(t_mdr), v.element_size);
	test_push_back(&v, 150);
	test_chunks(&v);
	test_it(&v);
	test_pop_back(&v, 55);
	test_it(&v);
	test_push_front(&v, 30);
	test_it(&v);
	test_pop_front(&v, 125);
	test_it(&v);
	ft_vclear(&v);
	return (0);
}
