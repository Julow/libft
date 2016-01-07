/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:09:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/07 22:02:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_bst.h"

static void	destroy_node(t_bst_node *node, void (*f)(), void *env)
{
	if (f != NULL)
		f(ENDOF(node), env);
	if (node->left != NULL)
		destroy_node(node->left, f, env);
	if (node->right != NULL)
		destroy_node(node->right, f, env);
	free(node);
}

void		ft_bst_destroy(t_bst *bst, void (*f)(), void *env)
{
	if (bst->root != NULL)
		destroy_node(bst->root, f, env);
}
