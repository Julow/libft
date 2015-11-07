/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_balance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 21:51:04 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 15:18:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_internal.h"

static void			restore_height(t_bst_node *node)
{
	int const			left_h = NODE_HEIGHT(node->left);
	int const			right_h = NODE_HEIGHT(node->right);

	node->height = MAX(left_h, right_h) + 1;
}

static t_bst_node	*bst_rot_r(t_bst_node *node)
{
	t_bst_node *const	tmp = node->left;

	node->left = tmp->right;
	tmp->right = node;
	restore_height(node);
	return (tmp);
}

static t_bst_node	*bst_rot_l(t_bst_node *node)
{
	t_bst_node *const	tmp = node->right;

	node->right = tmp->left;
	tmp->left = node;
	restore_height(node);
	return (tmp);
}

t_bst_node			*bst_balance(t_bst_node *node)
{
	int const			left_h = NODE_HEIGHT(node->left);
	int const			right_h = NODE_HEIGHT(node->right);
	int const			balance = right_h - left_h;

	node->height = MAX(left_h, right_h) + 1;
	if (balance > 1)
	{
		if (NODE_BALANCE(node->right) < 0)
		{
			node->right = bst_rot_r(node->right);
			restore_height(node->right);
		}
		return (bst_rot_l(node));
	}
	else if (balance < -1)
	{
		if (NODE_BALANCE(node->left) > 0)
		{
			node->left = bst_rot_l(node->left);
			restore_height(node->left);
		}
		return (bst_rot_r(node));
	}
	return (node);
}
