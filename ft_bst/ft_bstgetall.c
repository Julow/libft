/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstgetall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:10:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/17 18:04:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_internal.h"

static bool	bst_getall(t_bst_node *node, t_bst_cmp cmp, void const *match,
				bool (*f)(), void *env)
{
	int			diff;

	while (node != NULL)
	{
		diff = cmp(ENDOF(node), match);
		if (diff < 0)
			node = node->left;
		else
		{
			if (diff == 0 && (!f(ENDOF(node), match, env)
				|| !bst_getall(node->left, cmp, match, f, env)))
				return (false);
			node = node->right;
		}
	}
	return (true);
}

bool		ft_bst_getall(t_bst const *bst, void const *match, bool (*f)(),
				void *env)
{
	if (bst->root == NULL)
		return (true);
	return (bst_getall(bst->root, bst->match, match, f, env));
}
