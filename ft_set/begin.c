/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:35:36 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/13 20:00:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

/*
** begin: (<), left, right
** end: (<=), left, right
*/
void const		*ft_set_cbegin(t_set const *set, void const *key)
{
	t_set_node const	*node;
	t_set_node const	*tmp;

	if (key == NULL)
	{
		if ((node = set->data) == NULL)
			return (NULL);
		while (node->left != NULL)
			node = node->left;
		return (node);
	}
	node = NULL;
	tmp = set->data;
	while (true)
	{
		while (tmp != NULL && set->cmp(tmp, key) < 0)
			tmp = tmp->left;
		if (tmp == NULL)
			break ;
		node = tmp;
		tmp = tmp->right;
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
	tmp = set->data;
	while (true)
	{
		while (tmp != NULL && set->cmp(tmp, key) <= 0)
			tmp = tmp->left;
		if (tmp == NULL)
			break ;
		node = tmp;
		tmp = tmp->right;
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
