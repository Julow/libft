/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:33:02 by juloo             #+#    #+#             */
/*   Updated: 2015/08/23 15:52:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"
#include <stdlib.h>

typedef struct	s_lol
{
	int				a;
}				t_lol;

static t_ulong	test_add(t_vector *v, int count)
{
	int				i;
	t_ulong			t;

	i = -1;
	t = ft_clock(0);
	while (++i < count)
		ft_vpush_back(v, &(t_lol){rand()}, 1);
	t = ft_clock(t);
	ft_printf("Added %d: length:%d; capacity:%d; time:%lld\n",
		count, v->length, v->capacity, t);
	return (t);
}

static t_ulong	test_min_max(t_vector const *v)
{
	int				i;
	t_ulong			t;
	int				min;
	int				max;

	t = ft_clock(0);
	min = VECTOR_GET(t_lol, v, 0)->a;
	i = -1;
	while (++i < v->length)
		if (VECTOR_GET(t_lol, v, i)->a < min)
			min = VECTOR_GET(t_lol, v, i)->a;
	max = VECTOR_GET(t_lol, v, 0)->a;
	i = -1;
	while (++i < v->length)
		if (VECTOR_GET(t_lol, v, i)->a > max)
			max = VECTOR_GET(t_lol, v, i)->a;
	t = ft_clock(t);
	ft_printf("min: %d; max: %d; time: %lld\n", min, max, t);
	return (t);
}

static t_ulong	test_remove_bigger(t_vector *v, int than)
{
	int				i;
	int				removed;
	t_ulong			t;

	removed = 0;
	i = v->length;
	t = ft_clock(0);
	while (--i >= 0)
		if (VECTOR_GET(t_lol, v, i)->a > than)
		{
			ft_vremove(v, i, 1);
			removed++;
		}
	t = ft_clock(t);
	ft_printf("Removed: %d; length: %d; time: %lld\n", removed, v->length, t);
	return (t);
}

int				main(void)
{
	t_vector		v;
	t_ulong			add_t;
	t_ulong			rem_t;
	t_ulong			minmax_t;

	add_t = 0;
	rem_t = 0;
	minmax_t = 0;
	v = VECTOR(t_lol);
	srand(ft_clock(0));
	add_t += test_add(&v, 10);
	minmax_t += test_min_max(&v);
	add_t += test_add(&v, 100);
	add_t += test_add(&v, 10);
	add_t += test_add(&v, 1000);
	minmax_t += test_min_max(&v);
	add_t += test_add(&v, 10);
	add_t += test_add(&v, 10000);
	add_t += test_add(&v, 10);
	minmax_t += test_min_max(&v);
	rem_t += test_remove_bigger(&v, 1000000000);
	minmax_t += test_min_max(&v);
	add_t += test_add(&v, 1000);
	add_t += test_add(&v, 100);
	// minmax_t += test_min_max(&v);
	// rem_t += test_remove_bigger(&v, 1000000000);
	minmax_t += test_min_max(&v);
	add_t += test_add(&v, 100000);
	add_t += test_add(&v, 100);
	minmax_t += test_min_max(&v);
	add_t += test_add(&v, 1000000);
	add_t += test_add(&v, 100);
	minmax_t += test_min_max(&v);
	add_t += test_add(&v, 1000);
	add_t += test_add(&v, 10000000);
	add_t += test_add(&v, 1000);
	minmax_t += test_min_max(&v);
	ft_vclear(&v);
	ft_printf("Total add time: %lld\n", add_t);
	ft_printf("Total remove time: %lld\n", rem_t);
	ft_printf("Total minmax time: %lld\n", minmax_t);
	return (0);
}
