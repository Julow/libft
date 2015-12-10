/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:46:45 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

typedef struct	s_data
{
	int				a;
}				t_data;

static void		print_list(t_list *list)
{
	// t_data			*tmp;

	// tmp = LIST_IT(list);
	// ft_printf("[ ");
	// while ((tmp = LIST_PREV(tmp)))
	// {
	// 	ft_printf("%d ", tmp->a);
	// }
	// ft_printf("]\n");
}

static void		test_add_front(t_list *list, int count)
{
	t_data			*tmp;

	while (--count >= 0)
	{
		tmp = ft_listadd(list, NULL, 0);
		tmp->a = rand();
		print_list(list);
	}
}

static void		test_add_after(t_list *list, int min)
{
	t_data			*tmp;

	tmp = LIST_IT(list);
	while ((tmp = LIST_NEXT(tmp)))
	{
		if (tmp->a <= min)
		{
			tmp = ft_listadd(list, tmp, 0);
			tmp->a = rand();
			print_list(list);
		}
	}
}

static void		test_remove(t_list *list, int min)
{
	t_data			*tmp;

	tmp = LIST_IT(list);
	while ((tmp = LIST_NEXT(tmp)))
	{
		if (tmp->a <= min)
		{
			tmp = ft_listremove(list, tmp);
			print_list(list);
		}
	}
}

static int		test_cmp(t_data *a, t_data *b)
{
	return (a->a - b->a);
}

static void		test_sort(t_list *list)
{
	uint64_t			t;

	t = ft_clock(0);
	ft_listsort(list, &test_cmp);
	t = ft_clock(t);
	ft_printf("Sort (time: %llu us ; length: %d)\n", t, list->length);
	{
		// TMP
		t_data		*tmp = LIST_NEXT(LIST_IT(list));
		t_data		*prev = tmp;

		while ((tmp = LIST_NEXT(tmp)))
		{
			if (prev->a > tmp->a)
			{
				ft_printf("\033[31mNOT SORT\033[0m\n");
				exit(1);
			}
			prev = tmp;
		}
	}
}

int				main(void)
{
	t_list			list;

	srand(ft_clock(0));
	list = LIST(t_data);
	test_add_front(&list, 20);
	print_list(&list);
	test_add_after(&list, RAND_MAX / 2);
	print_list(&list);
	test_add_front(&list, 1500000000);
	// print_list(&list);
	test_sort(&list);
	// print_list(&list);
	// test_remove(&list, 0);
	// print_list(&list);
	// test_remove(&list, 100);
	// print_list(&list);
	return (0);
}
