/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 21:57:34 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 15:17:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BST_INTERNAL_H
# define FT_BST_INTERNAL_H

# include "ft_bst.h"

# define NODE_HEIGHT(N)		(((N) == NULL) ? 0 : (N)->height)
# define NODE_BALANCE(N)	(NODE_HEIGHT((N)->right) - NODE_HEIGHT((N)->left))

/*
** Balance a node
*/
t_bst_node		*bst_balance(t_bst_node *node);

#endif
