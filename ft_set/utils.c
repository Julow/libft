/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:46:30 by juloo             #+#    #+#             */
/*   Updated: 2017/02/19 02:54:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

void			set_node_rotate(t_set *set, t_set_node *node, bool left)
{
	t_vec2u const		i = left ? VEC2U(1, 2) : VEC2U(2, 1);
	t_set_node *const	pivot = SET_CHILD(node, i.y);
	t_set_node *const	parent = SET_PARENT(node);

	if (parent == NULL)
		set->root = pivot;
	else if (node == parent->left)
		parent->left = pivot;
	else
		parent->right = pivot;
	SET_SETPARENT(pivot, parent);
	SET_CHILD(node, i.y) = SET_CHILD(pivot, i.x);
	if (SET_CHILD(pivot, i.x) != NULL)
		SET_SETPARENT(SET_CHILD(pivot, i.x), node);
	SET_CHILD(pivot, i.x) = node;
	SET_SETPARENT(node, pivot);
	if (set->update != NULL)
	{
		if (SET_CHILD(pivot, i.x) != NULL)
			set->update(SET_CHILD(pivot, i.x));
		set->update(node);
		set->update(pivot);
	}
}

void			ft_set_update(t_set *set, void *element)
{
	if (set->update == NULL)
		return ;
	while (element != NULL)
	{
		set->update(element);
		element = SET_PARENT(element);
	}
}
