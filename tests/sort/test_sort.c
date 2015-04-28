/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 15:03:15 by juloo             #+#    #+#             */
/*   Updated: 2015/04/28 17:17:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define TEST(f)			test(argv + 1, argc - 1, &f, #f)

int				g_cmp_count = 0;

char const		*g_best_name = NULL;
t_ulong			g_best_time = 0;
int				g_best_cmp = 0;

static int		test_cmp(char *s1, char *s2)
{
	g_cmp_count++;
	return (ft_strcmp(s1, s2));
}

static void		test(char **argv, int length,
	void (*sort)(void **, int, int (*)()), char const *name)
{
	char			*array[length];
	int				i;
	t_ulong			start;

	ft_memcpy(array, argv, S(char*, length));
	g_cmp_count = 0;
	start = ft_clock(0);
	sort((void**)array, length, &test_cmp);
	start = ft_clock(start);
	ft_printf("%s %d %lluns\n", name + 3, g_cmp_count, start);
	i = -1;
	if (!ft_issort((void**)array, length, &test_cmp))
	{
		ft_printf("Not sorted: %{red}");
		while (++i < length)
			ft_printf(" %s", array[i]);
		ft_printf("%{reset}\n");
	}
	else if (g_best_name == NULL || g_cmp_count < g_best_cmp)
	{
		g_best_name = name;
		g_best_time = start;
		g_best_cmp = g_cmp_count;
	}
}

int				main(int argc, char **argv)
{
	TEST(ft_simplesort);
	TEST(ft_mergesort);
	TEST(ft_bubblesort);
	TEST(ft_insertsort);
	ft_printf("%{green}%s %{cyan}%dns (cmp: %d, len: %d)%{reset}\n",
		g_best_name, g_best_time, g_best_cmp, argc - 1);
	return (0);
}
