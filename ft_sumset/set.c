/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:53:48 by juloo             #+#    #+#             */
/*   Updated: 2017/03/02 17:32:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/sumset.h"
#include <stdlib.h>

static t_sumset_node	*node_get(t_sumset_node *node, uint32_t index)
{
	t_sumset_node			*left;

	if (node == NULL)
		return (NULL);
	left = node->set_h.left;
	if (left == NULL)
	{
		if (index == 0)
			return (node);
		return (node_get(node->set_h.right, index - 1));
	}
	if (index < left->length_sum)
		return (node_get(left, index));
	if (index > left->length_sum)
		return (node_get(node->set_h.right, index - left->length_sum - 1));
	return (node);
}

void			ft_sumset_insert(t_sumset *s, uint32_t index, uint32_t value)
{
	t_sumset_node *const	node = NEW(t_sumset_node);

	*node = (t_sumset_node){SET_HEAD(), value, 0, 0};
	ft_set_insert_before(&s->set, node, node_get(s->set.root, index));
}

void			ft_sumset_set(t_sumset *s, uint32_t index, uint32_t value)
{
	t_sumset_node *const	node = node_get(s->set.root, index);

	node->value = value;
	ft_set_update(&s->set, node);
}

void			ft_sumset_add(t_sumset *s, uint32_t index, int32_t add)
{
	t_sumset_node *const	node = node_get(s->set.root, index);

	node->value += add;
	ft_set_update(&s->set, node);
}

uint32_t		ft_sumset_remove(t_sumset *s, uint32_t index)
{
	t_sumset_node *const	node = node_get(s->set.root, index);
	uint32_t const			value = node->value;

	ft_set_remove(&s->set, node);
	free(node);
	return (value);
}
