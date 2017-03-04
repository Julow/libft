/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:53:31 by juloo             #+#    #+#             */
/*   Updated: 2017/03/04 17:00:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/sumset.h"

#define NODE_LEFT(N)		((t_sumset_node const*)(N)->set_h.left)

#define LEFT_LENGTH_SUM(N)	(NODE_LEFT(N) ? NODE_LEFT(N)->length_sum : 0)
#define LEFT_VALUE_SUM(N)	(NODE_LEFT(N) ? NODE_LEFT(N)->value_sum : 0)

t_vec2u			ft_sumset_get(t_sumset const *s, uint32_t index)
{
	t_sumset_node const	*node;
	uint32_t			sum;
	uint32_t			length_sum;

	sum = 0;
	if ((node = s->set.root) == NULL)
		return (VEC2U(0, 0));
	while (true)
	{
		length_sum = LEFT_LENGTH_SUM(node);
		if (index == length_sum)
			return (VEC2U(sum + LEFT_VALUE_SUM(node), node->value));
		if (index < length_sum)
		{
			node = node->set_h.left;
			continue ;
		}
		index -= length_sum + 1;
		sum += LEFT_VALUE_SUM(node) + node->value;
		if ((node = node->set_h.right) == NULL)
			return (VEC2U(sum, 0));
	}
}

t_vec2u			ft_sumset_index(t_sumset const *s, uint32_t sum)
{
	t_sumset_node const	*node;
	uint32_t			index;
	uint32_t			value_sum;

	index = 0;
	node = s->set.root;
	while (node != NULL)
	{
		value_sum = LEFT_VALUE_SUM(node) + node->value;
		if (sum < value_sum)
		{
			node = node->set_h.left;
			continue ;
		}
		sum -= value_sum;
		index += LEFT_LENGTH_SUM(node) + 1;
		node = node->set_h.right;
	}
	return (VEC2U(index, sum));
}
