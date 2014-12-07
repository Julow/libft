/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/ft_lstdelnext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 00:28:12 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/08 00:28:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdelnext(t_lst *lst, void (*f)(void*))
{
	t_lst			*tmp;

	if (lst->next == NULL)
		return ;
	tmp = lst->next;
	lst->next = tmp->next;
	f(tmp->data);
	free(tmp);
}
