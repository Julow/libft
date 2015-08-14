/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 19:29:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 02:05:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void			ft_lstadd(t_list **alst, t_list *add)
{
	if (alst == NULL || add == NULL)
		return ;
	add->next = *alst;
	*alst = add;
}
