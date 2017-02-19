/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:42:55 by juloo             #+#    #+#             */
/*   Updated: 2017/02/19 01:26:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

static void		set_balance(t_set *set, t_set_node *node)
{
	t_set_node		*parent;
	t_set_node		*gp;

	parent = SET_PARENT(node);
	gp = SET_PARENT(parent);
	if (node == parent->right && parent == gp->left)
		set_node_rotate(set, node = parent, true);
	else if (node == parent->left && parent == gp->right)
		set_node_rotate(set, node = parent, false);
	parent = SET_PARENT(node);
	gp = SET_PARENT(parent);
	SET_SETBLACK(parent);
	SET_SETRED(gp);
	set_node_rotate(set, gp,
		BOOL_OF(node == parent->right && parent == gp->right));
}

static void		set_check_balance(t_set *set, t_set_node *node)
{
	t_set_node		*parent;
	t_set_node		*gp;
	t_set_node		*uncle;

	parent = SET_PARENT(node);
	while (true)
	{
		gp = SET_PARENT(parent);
		ASSERT(gp != NULL);
		uncle = (gp->left == parent) ? gp->right : gp->left;
		if (uncle == NULL || !SET_ISRED(uncle))
			return (set_balance(set, node));
		SET_SETBLACK(parent);
		SET_SETBLACK(uncle);
		node = gp;
		parent = SET_PARENT(node);
		if (parent == NULL)
			break ;
		SET_SETRED(node);
		if (!SET_ISRED(parent))
			break ;
	}
}

bool			ft_set_insert(t_set *set, void *element, void const *key)
{
	t_set_node		*parent;
	t_set_node		**next;

	parent = NULL;
	next = (t_set_node**)&set->root;
	while (*next != NULL)
	{
		parent = *next;
		next = (set->cmp(parent, key) <= 0) ? &parent->left : &parent->right;
	}
	ASSERT(!(((uintptr_t)element) & 1), "IMPAIR POINTER");
	set->count++;
	*next = element;
	*(t_set_node*)element = (t_set_node){parent, NULL, NULL};
	if (parent != NULL)
	{
		SET_SETRED(*next);
		if (SET_ISRED(parent))
			set_check_balance(set, element);
	}
	ft_set_update(set, element);
	return (true);
}
