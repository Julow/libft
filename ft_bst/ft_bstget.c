/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/12/17 00:04:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_bst.h"

void		*ft_bst_get(t_bst const *bst, void *prev, void const *match)
{
	t_bst_node	*node;
	int			diff;

	if (prev != NULL)
		node = ((t_bst_node*)(prev - sizeof(t_bst_node)))->right;
	else
		node = bst->root;
	while (node != NULL)
	{
		diff = bst->match(ENDOF(node), match);
		if (diff < 0)
			node = node->left;
		else if (diff > 0)
			node = node->right;
		else
			return (ENDOF(node));
	}
	return (NULL);
}
