/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:46:45 by juloo             #+#    #+#             */
/*   Updated: 2015/09/04 21:46:57 by juloo            ###   ########.fr       */
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
	t_data			*tmp;

	tmp = LIST_IT(list);
	ft_printf("[ ");
	while ((tmp = LIST_PREV(tmp)))
	{
		ft_printf("%d ", tmp->a);
	}
	ft_printf("]\n");
}

static void		test_add_front(t_list *list, int count)
{
	t_data			*tmp;

	while (--count >= 0)
	{
		tmp = ft_listadd(list, NULL, 0);
		tmp->a = rand() % 100;
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
			tmp->a = 0;
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

int				main(void)
{
	t_list			list;

	srand(ft_clock(0));
	list = LIST(t_data);
	test_add_front(&list, 20);
	print_list(&list);
	test_add_after(&list, 50);
	print_list(&list);
	test_remove(&list, 0);
	print_list(&list);
	test_remove(&list, 100);
	print_list(&list);
	return (0);
}
