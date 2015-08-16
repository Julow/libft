/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:04:59 by juloo             #+#    #+#             */
/*   Updated: 2015/08/16 16:00:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			*ft_listadd(t_list *lst, void *next)
{
	void			*node;

	node = ft_emalloc(S(void*, 2) + lst->node_size) + S(void*, 2);
	ft_bzero(node, lst->node_size);
	lst->length++;
	if (next == lst->first)
		lst->first = node;
	LIST_NEXT(node) = next;
	if (next == NULL)
	{
		LIST_PREV(node) = lst->last;
		if (lst->last != NULL)
			LIST_NEXT(lst->last) = node;
		lst->last = node;
	}
	else
	{
		LIST_PREV(node) = LIST_PREV(next);
		if (LIST_PREV(next) != NULL)
			LIST_NEXT(LIST_PREV(node)) = node;
		LIST_PREV(next) = node;
	}
	return (node);
}
