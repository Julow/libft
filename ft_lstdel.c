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

void			ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list			*list;
	t_list			*tmp;

	list = (*alst)->next;
	while (list != NULL)
	{
		del(list->content, list->content_size);
		tmp = list;
		list = list->next;
		free(tmp);
	}
	ft_lstdelone(alst, del);
}
