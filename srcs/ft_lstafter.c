/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstafter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 19:45:42 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/29 19:45:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstafter(t_list *lst, t_list *add)
{
	if (lst == NULL || add == NULL)
		return ;
	add->next = lst->next;
	lst->next = add;
}
