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

#include "libft.h"

t_lst			*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst*))
{
	t_lst			*maped;
	t_lst			*add;
	t_lst			*tmp;

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
