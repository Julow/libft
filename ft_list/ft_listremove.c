/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:12:38 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:44:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_list.h"
#include <stdlib.h>

void			*ft_listremove(t_list *lst, void *node)
{
	void			*prev;

	prev = LIST_PREV(node);
	if (lst->first == node)
		lst->first = LIST_NEXT(node);
	else
		LIST_NEXT(prev) = LIST_NEXT(node);
	if (lst->last == node)
		lst->last = prev;
	else
		LIST_PREV(LIST_NEXT(node)) = prev;
	lst->length--;
	free(node - S(void*, 2));
	if (prev == NULL)
		return (LIST_IT(lst));
	return (prev);
}
