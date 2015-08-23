/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:33:02 by juloo             #+#    #+#             */
/*   Updated: 2015/08/23 14:15:16 by jaguillo         ###   ########.fr       */
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

int				main(void)
{
	t_vector		v;
	t_ulong			t;

	v = VECTOR(t_lol);
	srand(ft_clock(0));
	t = test_add(&v, 10);
	t += test_add(&v, 100);
	t += test_add(&v, 10);
	t += test_add(&v, 1000);
	t += test_add(&v, 10);
	t += test_add(&v, 10000);
	t += test_add(&v, 10);
	t += test_add(&v, 1000);
	t += test_add(&v, 100);
	t += test_add(&v, 100000);
	t += test_add(&v, 100);
	t += test_add(&v, 1000000);
	t += test_add(&v, 100);
	ft_printf("Total time: %lld\n", t);
	return (0);
}
