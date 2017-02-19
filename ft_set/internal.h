/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:45:21 by juloo             #+#    #+#             */
/*   Updated: 2017/02/19 02:54:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft/set.h"

typedef struct s_set_node		t_set_node;

/*
** ========================================================================== **
** Set implementation: red-black tree
*/

struct			s_set_node
{
	t_set_node		*parent;
	t_set_node		*left;
	t_set_node		*right;
};

# define SET_CHILD(NODE, I)	((t_set_node**)(NODE))[I]

# define SET_PARENT(NODE)	((t_set_node*)(_SET_P(NODE) & ~1))
# define SET_ISRED(NODE)	((bool)(_SET_P(NODE) & 1))

# define SET_SETRED(NODE)	(_SET_P(NODE) |= 1)
# define SET_SETBLACK(NODE)	(_SET_P(NODE) &= ~1)

# define SET_SETPARENT(N,P)	(_SET_P(N)=(uintptr_t)(P)|SET_ISRED(N))

/*
** Standard tree rotation
** -
** Update are performed where needed
*/
void			set_node_rotate(t_set *tree, t_set_node *node, bool left);

# define _SET_P(NODE)		*((uintptr_t*)&(((t_set_node*)(NODE))->parent))

#endif
