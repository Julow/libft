/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 19:32:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/29 19:32:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*map;
	t_list			*add;
	t_list			*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	map = f(lst);
	tmp = map;
	lst = lst->next;
	while (lst != NULL)
	{
		add = f(lst);
		if (add == NULL)
			return (NULL);
		tmp->next = add;
		tmp = add;
		lst = lst->next;
	}
	return (map);
}
