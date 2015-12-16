/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/12/16 18:39:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_internal.h"
#include <stdlib.h>

static t_bst_node	*bst_del_biggest(t_bst_node *node, t_bst_node **dst)
{
	if (node->right == NULL)
	{
		*dst = node;
		return (NULL);
	}
	node->right = bst_del_biggest(node->right, dst);
	return (bst_balance(node));
}

static t_bst_node	*bst_del_node(t_bst *bst, t_bst_node *node)
{
	t_bst_node *const	right = node->right;
	t_bst_node *const	left = node->left;
	t_bst_node			*big;

	bst->length--;
	free(node);
	if (left == NULL)
		return (right);
	big->left = bst_del_biggest(left, &big);
	big->right = right;
	return (big);
}

static t_bst_node	*bst_del(t_bst *bst, t_bst_node *node, void const *match)
{
	int			diff;

	if (node == NULL)
		return (NULL);
	diff = bst->match(ENDOF(node), match);
	if (diff < 0)
		node->left = bst_del(bst, node->left, match);
	else if (diff > 0)
		node->right = bst_del(bst, node->right, match);
	else if ((node = bst_del_node(bst, node)) == NULL)
		return (NULL);
	return (bst_balance(node));
}

void				ft_bst_del(t_bst *bst, void const *match)
{
	bst->root = bst_del(bst, bst->root, match);
}
