/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:33:02 by juloo             #+#    #+#             */
/*   Updated: 2015/08/23 15:03:35 by jaguillo         ###   ########.fr       */
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

static void		test_min_max(t_vector *v)
{
	t_lol			*lol;
	t_lol const		*end = VECTOR_END(v);
	t_ulong			t;
	int				min;
	int				max;

	t = ft_clock(0);
	lol = VECTOR_IT(v);
	if (++lol < end)
		min = lol->a;
	while (++lol < end)
		if (lol->a < min)
			min = lol->a;
	lol = VECTOR_IT(v);
	if (++lol < end)
		max = lol->a;
	while (++lol < end)
		if (lol->a > max)
			max = lol->a;
	t = ft_clock(t);
	ft_printf("min: %d; max: %d; time: %lld\n", min, max, t);
}

int				main(void)
{
	t_vector		v;
	t_ulong			t;

	v = VECTOR(t_lol);
	srand(ft_clock(0));
	t = test_add(&v, 10);
	test_min_max(&v);
	t += test_add(&v, 100);
	t += test_add(&v, 10);
	t += test_add(&v, 1000);
	test_min_max(&v);
	t += test_add(&v, 10);
	t += test_add(&v, 10000);
	t += test_add(&v, 10);
	test_min_max(&v);
	t += test_add(&v, 1000);
	t += test_add(&v, 100);
	t += test_add(&v, 100000);
	test_min_max(&v);
	t += test_add(&v, 100);
	t += test_add(&v, 1000000);
	t += test_add(&v, 100);
	test_min_max(&v);
	t += test_add(&v, 1000);
	t += test_add(&v, 10000000);
	t += test_add(&v, 1000);
	test_min_max(&v);
	ft_printf("Total time: %lld\n", t);
	return (0);
}
