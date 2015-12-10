/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:19:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_bst.h"

static bool		bst_iter(t_bst_node *node, bool (*f)(void*, void*), void *env)
{
	while (true)
	{
		if (node->left != NULL && !bst_iter(node->left, f, env))
			return (false);
		if (!f(ENDOF(node), env))
			return (false);
		if (node->right == NULL)
			break ;
		node = node->right;
	}
	return (true);
}

bool			ft_bst_iter(t_bst *bst, bool (*f)(void*, void*), void *env)
{
	if (bst->root == NULL)
		return (true);
	return (bst_iter(bst->root, f, env));
}
