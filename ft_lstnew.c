/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 19:18:14 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/29 19:18:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*lst;

	lst = MAL1(t_list);
	if (lst == NULL)
		return (NULL);
	lst->content = (void*)content;
	lst->content_size = (content == NULL) ? 0 : content_size;
	lst->next = NULL;
	return (lst);
}
