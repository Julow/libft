/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:03:43 by juloo             #+#    #+#             */
/*   Updated: 2017/03/01 01:17:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/libft.h"
#include "ft/sumset.h"

/*
** ========================================================================== **
*/

void			test_get(t_sumset const *sumset)
{
	uint32_t		i;
	uint32_t		sum;
	t_vec2u			tmp;

	uint64_t		t = ft_clock(0);
	sum = 0;
	i = 0;
	while (i < SUMSET_LENGTH(*sumset))
	{
		tmp = ft_sumset_get(sumset, i);
		ASSERT(tmp.x == sum);
		sum += tmp.y;
		i++;
	}
	t = ft_clock(t);
	ft_printf("test_get: %llu ms%n", t);
}

void			test_index(t_sumset const *sumset)
{
	t_vec2u			index;
	t_vec2u			tmp;
	uint32_t		i;

	uint64_t		t = ft_clock(0);
	i = 0;
	while (i < SUMSET_SUM(*sumset))
	{
		index = ft_sumset_index(sumset, i);
		tmp = ft_sumset_get(sumset, index.x);

		ASSERT(i == tmp.x + index.y, "INDEX ERROR");
		i += 2000;
	}
	t = ft_clock(t);
	ft_printf("test_index: %llu ms%n", t);
}

/*
** ========================================================================== **
*/

#define MAX_VAL			100000

int				main(void)
{
	t_sumset		s;
	t_vec2u			tmp;

	s = SUMSET();

	{

#define PUSH_COUNT		1000000

		uint32_t		i;

		i = 0;
		while (i < PUSH_COUNT)
		{
			ft_sumset_insert(&s, i, ft_rand(0, MAX_VAL));
			i++;
		}
	}

	test_get(&s);
	tmp = ft_sumset_get(&s, SUMSET_LENGTH(s) - 1);
	ASSERT(SUMSET_SUM(s) == tmp.x + tmp.y, "SUMSET_SUM ERROR");
	test_index(&s);
	TRACE("PUSH OK");

	uint32_t const	sum_a = SUMSET_SUM(s);

	{

#define INSERT_COUNT	1000000

		uint32_t		i;

		i = 0;
		while (i < INSERT_COUNT)
		{
			// ft_sumset_insert(&s, i, ft_rand(0, MAX_VAL));
			ft_sumset_insert(&s, i, !i);
			i += 2;
		}
	}

	test_get(&s);
	tmp = ft_sumset_get(&s, SUMSET_LENGTH(s) - 1);
	ASSERT(SUMSET_SUM(s) == tmp.x + tmp.y, "SUMSET_SUM ERROR");
	test_index(&s);
	ASSERT(SUMSET_SUM(s) == sum_a + 1);
	TRACE("INSERT OK");

	{
		uint32_t const	end = SUMSET_LENGTH(s);
		uint32_t		i;

		i = 0;
		while (i < end)
		{
			ft_sumset_set(&s, i, 1);
			i++;
		}
	}

	test_get(&s);
	tmp = ft_sumset_get(&s, SUMSET_LENGTH(s) - 1);
	ASSERT(SUMSET_SUM(s) == tmp.x + tmp.y, "SUMSET_SUM ERROR");
	test_index(&s);
	ASSERT(SUMSET_LENGTH(s) == SUMSET_SUM(s), "SET FAIL");
	TRACE("SET OK");

	return (0);
}
