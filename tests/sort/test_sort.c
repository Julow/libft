/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 15:03:15 by juloo             #+#    #+#             */
/*   Updated: 2015/04/27 19:17:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

#define TEST(f)			test(argv + 1, argc - 1, &f, #f)

int				g_cmp_count = 0;

static int		test_cmp(char *s1, char *s2)
{
	g_cmp_count++;
	return (ft_strcmp(s1, s2));
}

#define FT_CPS			1000000000

t_ulong			ft_clock(t_ulong start)
{
	struct timespec	tmp;

	clock_gettime(CLOCK_MONOTONIC, &tmp);
	return (tmp.tv_sec * FT_CPS + tmp.tv_nsec - start);
}

// static void		ft_timediff(struct timespec *start, struct timespec *end)
// {
// 	struct timespec	tmp;

// 	if (end->tv_sec != start->tv_sec)
// 	{
// 		tmp.tv_sec = end->tv_sec - start->tv_sec;
// 		tmp.tv_nsec = 1000000000 - start->tv_nsec;
// 	}
// 	else
// 	{
// 		tmp.tv_sec = 0;
// 		tmp.tv_nsec = 0;
// 	}
// 	tmp.tv_nsec += end->tv_nsec - start->tv_nsec;
// 	ft_printf("%d.%09ds", tmp.tv_sec, tmp.tv_nsec);
// }

static void		test(char **argv, int length, void (*sort)(void **, int, int (*)()), char const *name)
{
	char			*array[length];
	int				i;
	t_ulong			start;

	ft_memcpy(array, argv, S(char*, length));
	g_cmp_count = 0;
	start = ft_clock(0);
	sort((void**)array, length, &test_cmp);
	start = ft_clock(start);
	ft_printf("%{cyan}%s%{reset}%>27 cmp: %-10d time: %'lluns\n", name, g_cmp_count, start);
	i = -1;
	if (!ft_issort((void**)array, length, &test_cmp))
	{
		ft_printf("Not sorted: %{red}");
		while (++i < length)
			ft_printf(" %s", array[i]);
		ft_printf("%{reset}\n");
	}
}

int				main(int argc, char **argv)
{
	ft_printf("[%{green}len: %d%{reset}]\n", argc - 1);
	TEST(ft_simplesort);
	TEST(ft_mergesort);
	return (0);
}
