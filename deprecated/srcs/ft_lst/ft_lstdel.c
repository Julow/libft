/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 19:24:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 02:05:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

void			ft_lstdel(t_list **alst, void (*del)(void*, t_uint))
{
	t_list			*tmp;

	if (alst == NULL)
		return ;
	while (*alst != NULL)
	{
		if (del != NULL)
			del((*alst)->content, (*alst)->content_size);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
	*alst = NULL;
}
