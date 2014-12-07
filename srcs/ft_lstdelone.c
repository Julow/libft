/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:06:50 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/05 15:06:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

void			ft_lstdelone(t_lst **alst, void (*f)(void*))
{
	if (alst == NULL || *alst == NULL)
		return ;
	f((*alst)->data);
	free(*alst);
	*alst = NULL;
}
