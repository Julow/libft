/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:37:23 by juloo             #+#    #+#             */
/*   Updated: 2017/02/19 00:52:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

void const		*ft_set_cget(t_set const *set, void const *key)
{
	t_set_node const	*node;
	int					diff;

	node = set->root;
	while (node != NULL && (diff = set->cmp(node, key)) != 0)
		node = (diff < 0) ? node->left : node->right;
	return (node);
}

void			*ft_set_get(t_set *set, void const *key)
{
	return ((void*)ft_set_cget(set, key));
}
