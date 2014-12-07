/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:10:39 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/05 15:10:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdel(t_lst **alst, void (*f)(void*))
{
	t_lst			*list;
	t_lst			*tmp;

	list = (*alst)->next;
	while (list != NULL)
	{
		f(list->data);
		tmp = list;
		list = list->next;
		free(tmp);
	}
	ft_lstdelone(alst, f);
}
