/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oset.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:14:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/27 15:40:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/oset.h"

bool			ft_oset_insert(t_oset *set, void *element, void const *key)
{
	if (!ft_set_insert(&set->set, element, key))
		return (false);
	((t_oset_h*)element)->next = NULL;
	((t_oset_h*)element)->prev = set->last;
	if (set->first == NULL)
		set->first = element;
	else
		((t_oset_h*)set->last)->next = element;
	set->last = element;
	return (true);
}

void			ft_oset_remove(t_oset *set, void *element)
{
	t_oset_h *const	h = element;

	ft_set_remove(&set->set, element);
	if (h->prev == NULL)
		set->first = h->next;
	else
		((t_oset_h*)h->prev)->next = h->next;
	if (h->next == NULL)
		set->last = h->prev;
	else
		((t_oset_h*)h->next)->prev = h->prev;
}
