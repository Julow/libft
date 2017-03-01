/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:54:29 by juloo             #+#    #+#             */
/*   Updated: 2017/02/28 23:16:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/sumset.h"

void			sumset_node_update(t_sumset_node *node)
{
	static t_sumset_node const	dummy = (t_sumset_node){SET_HEAD(), 0, 0, 0};
	t_sumset_node const *const	l = node->set_h.left ? node->set_h.left : &dummy;
	t_sumset_node const *const	r = node->set_h.right ? node->set_h.right : &dummy;

	node->length_sum = l->length_sum + 1 + r->length_sum;
	node->value_sum = l->value_sum + node->value + r->value_sum;
}
