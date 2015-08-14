/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 02:03:15 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 02:04:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include "libft.h"

/*
** ========================================================================== **
** Storage
** -
** Deprecated
** ---
** + fast add
** + fast insert/remove
** + fast inter
** - slow
** - bad implementation
*/

typedef struct	s_list
{
	void			*content;
	t_uint			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(const void *content, t_uint content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, t_uint));
void			ft_lstdelnext(t_list *lst, void (*f)(void*, t_uint));
void			ft_lstdel(t_list **alst, void (*del)(void*, t_uint));
void			ft_lstadd(t_list **alst, t_list *add);
void			ft_lstafter(t_list *lst, t_list *add);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
