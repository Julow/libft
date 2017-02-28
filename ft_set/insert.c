/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:42:55 by juloo             #+#    #+#             */
/*   Updated: 2017/02/28 12:24:12 by jaguillo         ###   ########.fr       */
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

static void		insert_node(t_set *set, t_set_node *element, t_set_node *parent)
{
	ASSERT(!(((uintptr_t)element) & 1), "IMPAIR POINTER");
	set->count++;
	*element = (t_set_node){parent, NULL, NULL};
	if (parent != NULL)
	{
		SET_SETRED(element);
		if (SET_ISRED(parent))
			set_check_balance(set, element);
	}
	ft_set_update(set, element);
}

void			ft_set_insert(t_set *set, void *element, void const *key)
{
	t_set_node		*parent;
	t_set_node		**next;

	parent = NULL;
	next = (t_set_node**)&set->root;
	while (*next != NULL)
	{
		parent = *next;
		next = (set->cmp(parent, key) >= 0) ? &parent->left : &parent->right;
	}
	*next = element;
	insert_node(set, element, parent);
}

void			ft_set_insert_before(t_set *set, void *element, void *before)
{
	t_set_node		*parent;
	t_set_node		**next;

	parent = before;
	next = parent ? &parent->left : (t_set_node**)&set->root;
	while (*next != NULL)
	{
		parent = *next;
		next = &parent->right;
	}
	*next = element;
	insert_node(set, element, parent);
}
