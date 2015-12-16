/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/12/16 19:16:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_bst.h"

void		*ft_bst_get(t_bst const *bst, void const *match)
{
	t_bst_node	*node;
	int			diff;

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
