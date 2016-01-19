/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:04:59 by juloo             #+#    #+#             */
/*   Updated: 2016/01/19 16:12:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_list.h"

void			*ft_listadd(t_list *lst, void *after, int extra_size)
{
	void			*node;

	node = MALLOC(S(void*, 2) + lst->node_size + extra_size) + S(void*, 2);
	ft_bzero(node, lst->node_size + extra_size);
	lst->length++;
	if (after == lst->last)
		lst->last = node;
	LIST_PREV(node) = after;
	if (after == NULL)
	{
		LIST_NEXT(node) = lst->first;
		if (lst->first != NULL)
			LIST_PREV(lst->first) = node;
		lst->first = node;
	}
	else
	{
		LIST_NEXT(node) = LIST_NEXT(after);
		if (LIST_NEXT(after) != NULL)
			LIST_PREV(LIST_NEXT(node)) = node;
		LIST_NEXT(after) = node;
	}
	return (node);
}
