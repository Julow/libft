/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:29:24 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/05 14:29:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*list;
	void			*copy;

	list = MAL1(t_list);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		copy = malloc(content_size);
		ft_memmove(copy, content, content_size);
		list->content = copy;
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
