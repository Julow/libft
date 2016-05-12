/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:38:05 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 23:00:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

void const		*ft_set_cfirst(t_set const *set, void const *key)
{
	t_set_node const	*node;
	t_set_node const	*tmp;
	int					diff;

	if (key == NULL)
	{
		if ((node = set->data) == NULL)
			return (NULL);
		while (node->left != NULL)
			node = node->left;
		return (node);
	}
	node = ft_set_cget(set, key);
	while (node != NULL)
	{
		tmp = node->left;
		while (tmp != NULL && (diff = set->cmp(tmp, key)) != 0)
			tmp = tmp->right;
		if (tmp == NULL)
			break ;
		node = tmp;
	}
	return (node);
}

void const		*ft_set_clast(t_set const *set, void const *key)
{
	t_set_node const	*node;
	t_set_node const	*tmp;
	int					diff;

	if (key == NULL)
	{
		if ((node = set->data) == NULL)
			return (NULL);
		while (node->right != NULL)
			node = node->right;
		return (node);
	}
	node = ft_set_cget(set, key);
	while (node != NULL)
	{
		tmp = node->right;
		while (tmp != NULL && (diff = set->cmp(tmp, key)) != 0)
			tmp = tmp->left;
		if (tmp == NULL)
			break ;
		node = tmp;
	}
	return (node);
}

void			*ft_set_first(t_set *set, void const *key)
{
	return ((void*)ft_set_cfirst(set, key));
}

void			*ft_set_last(t_set *set, void const *key)
{
	return ((void*)ft_set_clast(set, key));
}
