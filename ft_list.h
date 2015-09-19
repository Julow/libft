/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:00:32 by juloo             #+#    #+#             */
/*   Updated: 2015/09/19 12:12:23 by jaguillo         ###   ########.fr       */
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

struct			s_list
{
	void			*first;
	void			*last;
	int				length;
	int const		node_size;
};

/*
** Create a list of t
*/
# define LIST(t)		((t_list){NULL, NULL, 0, sizeof(t)})

/*
** Create an iterator
** (the pointer is invalid until LIST_NEXT or LIST_PREV is called)
*/
# define LIST_IT(l)		(((void*)(l)) + S(void*, 2))

/*
** Increment or decrement the iterator
*/
# define LIST_NEXT(n)	(*(((void**)(n)) - 2))
# define LIST_PREV(n)	(*(((void**)(n)) - 1))

/*
** Create a new node and add it after 'after'
** Each nodes are alloc'd (lst->node_size + extra_size)
** if 'after' is NULL add to the front
** the node is bzero
** Should not be used with 'after' not NULL while itering using LIST_PREV
** Return the new node (it's also the iterator if 'after' is not NULL)
*/
void			*ft_listadd(t_list *lst, void *after, int extra_size);

/*
** Remove a node
** Should not be used while itering using LIST_PREV
** Return a new iterator (invalid until next call to LIST_NEXT)
*/
void			*ft_listremove(t_list *lst, void *node);

#endif
