/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 21:43:26 by juloo             #+#    #+#             */
/*   Updated: 2015/09/20 02:21:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void		*list_push(void *lst, void *add)
{
	LIST_NEXT(lst) = add;
	return (LIST_NEXT(add));
}

static void		*list_merge(void *lst, void *add, int (*cmp)(void*, void*))
{
	void			*merged;
	void			*first;

	if (cmp(lst, add) > 0)
		add = LIST_NEXT(first = add);
	else
		lst = LIST_NEXT(first = lst);
	merged = first;
	while (true)
	{
		if (lst == NULL)
		{
			if (add == NULL)
				break ;
			add = list_push(merged, add);
		}
		else if (add == NULL || cmp(lst, add) <= 0)
			lst = list_push(merged, lst);
		else
			add = list_push(merged, add);
		merged = LIST_NEXT(merged);
	}
	return (first);
}

static void		*list_n(void *lst, int n)
{
	while (--n >= 0)
		lst = LIST_NEXT(lst);
	return (lst);
}

static void		*list_split(void *lst, int length, int (*cmp)(void*, void*))
{
	if (LIST_PREV(lst) != NULL)
		LIST_NEXT(LIST_PREV(lst)) = NULL;
	if (length <= 2)
	{
		if (length < 2)
			return (lst);
		if (cmp(lst, LIST_NEXT(lst)) <= 0)
			return (lst);
		cmp = LIST_NEXT(lst);
		LIST_NEXT(lst) = LIST_NEXT(cmp);
		LIST_NEXT(cmp) = lst;
		return (cmp);
	}
	return (list_merge(
		list_split(list_n(lst, length / 2), (length + 1) / 2, cmp),
		list_split(lst, length / 2, cmp),
		cmp
	));
}

void			ft_listsort(t_list *lst, int (*cmp)())
{
	void			*tmp;
	void			*prev;

	lst->first = list_split(LIST_NEXT(LIST_IT(lst)), lst->length, cmp);
	tmp = LIST_IT(lst);
	prev = NULL;
	if (tmp != NULL)
		while ((tmp = LIST_NEXT(tmp)))
		{
			LIST_PREV(tmp) = prev;
			prev = tmp;
		}
	lst->last = prev;
}
