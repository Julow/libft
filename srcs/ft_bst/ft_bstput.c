/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/10/20 22:06:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_bst_internal.h"

static t_bst_node	*new_node(t_bst_put *tmp)
{
	t_bst_node	*node;

	node = ft_emalloc(sizeof(t_bst_node) + tmp->bst->node_size + tmp->extra_size);
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	ft_memcpy(ENDOF(node), tmp->data, tmp->bst->node_size);
	tmp->dst = ENDOF(node);
	return (node);
}

static t_bst_node	*bst_put(t_bst_put *tmp, t_bst_node *node)
{
	if (node == NULL)
	{
		tmp->bst->length++;
		return (new_node(tmp));
	}
	if (tmp->bst->cmp(tmp->data, ENDOF(node)) < 0)
		node->left = bst_put(tmp, node->left);
	else
		node->right = bst_put(tmp, node->right);
	return (bst_balance(node));
}

void				*ft_bst_put(t_bst *bst, void const *data, uint32_t extra)
{
	t_bst_put	tmp;

	tmp = (t_bst_put){bst, data, extra, NULL};
	bst->root = bst_put(&tmp, bst->root);
	return (tmp.dst);
}
