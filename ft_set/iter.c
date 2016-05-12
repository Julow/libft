/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:25:21 by juloo             #+#    #+#             */
/*   Updated: 2016/05/09 15:33:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

void const		*ft_set_cnext(void const *element)
{
	t_set_node const	*tmp;

	if ((tmp = ((t_set_node const*)element)->right) != NULL)
	{
		while (tmp->left != NULL)
			tmp = tmp->left;
	}
	else
	{
		while ((tmp = SET_PARENT(element)) != NULL && element == tmp->right)
			element = tmp;
	}
	return (tmp);
}

void const		*ft_set_cprev(void const *element)
{
	t_set_node const	*tmp;

	if ((tmp = ((t_set_node const*)element)->left) != NULL)
	{
		while (tmp->right != NULL)
			tmp = tmp->right;
	}
	else
	{
		while ((tmp = SET_PARENT(element)) != NULL && element == tmp->left)
			element = tmp;
	}
	return (tmp);
}

void			*ft_set_next(void *element)
{
	return ((void*)(ft_set_cnext(element)));
}

void			*ft_set_prev(void *element)
{
	return ((void*)(ft_set_cprev(element)));
}
