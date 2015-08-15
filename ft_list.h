/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 01:00:32 by juloo             #+#    #+#             */
/*   Updated: 2015/08/16 01:19:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

/*
** ========================================================================== **
** List
** -
** Storage
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

#define LIST(t)			((t_list){NULL, NULL, 0, sizeof(t)})

#define LIST_IT(l)		(((void*)(l)) + sizeof(t_l_node))

#define LIST_NEXT(n)	(*(((void**)(n)) - 2))
#define LIST_PREV(n)	(*(((void**)(n)) - 1))

/*
** Create a new node and place it before 'next'
** Return the new node
*/
void			*ft_listbefore(t_list *lst, void *next);

/*
** Create a new node and place it after 'prev'
** Return the new node
*/
void			*ft_listafter(t_list *lst, void *prev);

/*
** Remove a node
*/
void			ft_listremove(t_list *lst, void *node);

#endif
