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

#include "ft_lst.h"

t_lst			*ft_lstnew(void *data)
{
	t_lst			*list;

	list = MAL1(t_lst);
	list->data = data;
	list->next = NULL;
	return (list);
}
