/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:00:32 by juloo             #+#    #+#             */
/*   Updated: 2015/08/16 01:58:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

/*
** ========================================================================== **
** Double chained list
** -
*/

typedef struct	s_l_node
{
	void			*next;
	void			*prev;
}				t_l_node;

typedef struct	s_list
{
	void			*first;
	void			*last;
	int				length;
	int const		node_size;
}				t_list;

/*
** Create a list of t
*/
#define LIST(t)			((t_list){NULL, NULL, 0, sizeof(t)})

/*
** Create an iterator
** (the pointer is invalid until LIST_NEXT or LIST_PREV is called)
*/
#define LIST_IT(l)		(((void*)(l)) + sizeof(t_l_node))

/*
** Increment or decrement the iterator
*/
#define LIST_NEXT(n)	(*(((void**)(n)) - 2))
#define LIST_PREV(n)	(*(((void**)(n)) - 1))

/*
** Create a new node and add it before 'next'
** if 'next' is NULL add to the end
** the node is bzero
** Return the new node
*/
void			*ft_listadd(t_list *lst, void *next);

/*
** Remove a node
*/
void			ft_listremove(t_list *lst, void *node);

#endif
