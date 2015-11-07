/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/10/20 19:53:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bst.h"

void		*ft_bst_max(t_bst *bst)
{
	t_bst_node	*tmp;

	if (bst->root == NULL)
		return (NULL);
	tmp = bst->root;
	while (tmp->right != NULL)
		tmp = tmp->right;
	return (ENDOF(tmp));
}
