/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:31:30 by juloo             #+#    #+#             */
/*   Updated: 2016/05/09 14:45:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

static void		set_balance_end(t_set *set, t_set_node *node,
					t_set_node *parent, t_vec2u i)
{
	if (SET_CHILD(node, i.y) == NULL
		|| !SET_ISRED(SET_CHILD(node, i.y)))
	{
		SET_SETBLACK(SET_CHILD(node, i.x));
		SET_SETRED(node);
		set_node_rotate(set, node, i.y == 1);
		node = SET_CHILD(parent, i.y);
	}
	if (SET_ISRED(parent))
		SET_SETRED(node);
	else
		SET_SETBLACK(node);
	SET_SETBLACK(parent);
	SET_SETBLACK(SET_CHILD(node, i.y));
	set_node_rotate(set, parent, i.x == 1);
}

static void		set_balance(t_set *set, t_set_node *node)
{
	t_set_node		*sibling;
	t_set_node		*parent;
	t_vec2u			i;

	while ((parent = SET_PARENT(node)) != NULL && !SET_ISRED(node))
	{
		i = ((node == parent->left) || (parent->left == NULL
				&& node != parent->right)) ? VEC2U(1, 2) : VEC2U(2, 1);
		if (SET_ISRED(sibling = SET_CHILD(parent, i.y)))
		{
			SET_SETBLACK(sibling);
			SET_SETRED(parent);
			set_node_rotate(set, parent, i.x == 1);
			sibling = SET_CHILD(parent, i.y);
		}
		if ((sibling->left == NULL || !SET_ISRED(sibling->left))
			&& (sibling->right == NULL || !SET_ISRED(sibling->right)))
		{
			SET_SETRED(sibling);
			node = parent;
			continue ;
		}
		set_balance_end(set, sibling, parent, i);
		break ;
	}
	SET_SETBLACK(node);
}

static void		set_swap_node(t_set *set, t_set_node *a, t_set_node *b)
{
	t_set_node		*parent;

	if (a->left == a)
		a->left = b;
	else if (a->right == a)
		a->right = b;
	if (a->left != NULL)
		SET_SETPARENT(a->left, a);
	if (a->right != NULL)
		SET_SETPARENT(a->right, a);
	if ((parent = SET_PARENT(a)) == NULL)
		set->data = a;
	else if (parent->left == b)
		parent->left = a;
	else if (parent->right == b)
		parent->right = a;
}

static void		set_swap(t_set *set, t_set_node *a, t_set_node *b)
{
	t_set_node		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	set_swap_node(set, a, b);
	set_swap_node(set, b, a);
}

void			ft_set_remove(t_set *set, void *element)
{
	t_set_node			*tmp;
	t_set_node *const	node = (t_set_node*)element;
	t_set_node			*parent;

	set->count--;
	if (node->left != NULL && node->right != NULL)
		set_swap(set, ft_set_next(node), node);
	tmp = (node->left != NULL) ? node->left : node->right;
	if ((parent = SET_PARENT(node)) == NULL)
		set->data = tmp;
	else if (node == parent->left)
		parent->left = tmp;
	else
		parent->right = tmp;
	if (tmp == NULL)
		tmp = node;
	SET_SETPARENT(tmp, parent);
	if (!SET_ISRED(node))
		set_balance(set, tmp);
	*node = (t_set_node){NULL, NULL, NULL};
}
