/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:35:36 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/27 22:42:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

void const		*ft_set_cbegin(t_set const *set, void const *key)
{
	t_set_node const	*node;
	t_set_node const	*tmp;

	if (key == NULL)
	{
		if ((node = set->root) == NULL)
			return (NULL);
		while (node->left != NULL)
			node = node->left;
		return (node);
	}
	node = NULL;
	tmp = set->root;
	while (true)
	{
		while (tmp != NULL && set->cmp(tmp, key) < 0)
			tmp = tmp->right;
		if (tmp == NULL)
			break ;
		node = tmp;
		tmp = tmp->left;
	}
	return (node);
}

void const		*ft_set_cend(t_set const *set, void const *key)
{
	t_set_node const	*node;
	t_set_node const	*tmp;

	if (key == NULL)
		return (NULL);
	node = NULL;
	tmp = set->root;
	while (true)
	{
		while (tmp != NULL && set->cmp(tmp, key) <= 0)
			tmp = tmp->right;
		if (tmp == NULL)
			break ;
		node = tmp;
		tmp = tmp->left;
	}
	return (node);
}

void			*ft_set_begin(t_set *set, void const *key)
{
	return ((void*)ft_set_cbegin(set, key));
}

void			*ft_set_end(t_set *set, void const *key)
{
	return ((void*)ft_set_cend(set, key));
}
