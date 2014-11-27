/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:39:04 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/05 15:39:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*maped;
	t_list			*add;
	t_list			*tmp;

	if (lst == NULL)
		return (NULL);
	maped = f(lst);
	tmp = maped;
	lst = lst->next;
	while (lst != NULL)
	{
		add = f(lst);
		tmp->next = add;
		tmp = add;
		lst = lst->next;
	}
	return (maped);
}
