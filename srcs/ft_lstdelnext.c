/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 19:52:35 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/29 19:52:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdelnext(t_list *lst, void (*f)(void*, t_uint))
{
	t_list			*tmp;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst->next;
	lst->next = tmp->next;
	if (f != NULL)
		f(tmp->content, tmp->content_size);
	free(tmp);
}
