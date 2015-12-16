/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/12/16 18:09:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_bst.h"

void		*ft_bst_min(t_bst const *bst)
{
	t_bst_node	*tmp;

	if (bst->root == NULL)
		return (NULL);
	tmp = bst->root;
	while (tmp->left != NULL)
		tmp = tmp->left;
	return (ENDOF(tmp));
}
