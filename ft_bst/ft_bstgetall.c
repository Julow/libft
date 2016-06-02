/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstgetall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:10:16 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/02 15:08:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_internal.h"

static bool	bst_getall(t_bst_node *node, t_bst_cmp cmp, void const *match,
				t_callback const *callback)
{
	int					diff;

	while (node != NULL)
	{
		diff = cmp(ENDOF(node), match);
		if (diff < 0)
			node = node->left;
		else
		{
			if (diff == 0 && (!CALL(bool, *callback, ENDOF(node), match)
				|| !bst_getall(node->left, cmp, match, callback)))
				return (false);
			node = node->right;
		}
	}
	return (true);
}

bool		ft_bst_getall(t_bst const *bst, void const *match, bool (*f)(),
				void *env)
{
	t_callback const	callback = CALLBACK(f, env);

	if (bst->root == NULL)
		return (true);
	return (bst_getall(bst->root, bst->match, match, &callback));
}
