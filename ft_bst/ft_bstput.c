/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/12/16 18:38:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_internal.h"

static t_bst_node	*bst_put(t_bst_cmp match_f, t_bst_node *dst,
						void const *match, t_bst_node *node)
{
	if (node == NULL)
		return (dst);
	if (match_f(ENDOF(node), match) < 0)
		node->left = bst_put(match_f, dst, match, node->left);
	else
		node->right = bst_put(match_f, dst, match, node->right);
	return (bst_balance(node));
}

void				*ft_bst_put(t_bst *bst, void const *match, uint32_t extra)
{
	t_bst_node	*node;

	node = ft_emalloc(sizeof(t_bst_node) + bst->node_size + extra);
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	bst->root = bst_put(bst->match, node, match, bst->root);
	bst->length++;
	return (ENDOF(node));
}
