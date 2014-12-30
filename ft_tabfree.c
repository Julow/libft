/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:05:07 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:05:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_tabfree(t_tab *tab)
{
	t_byte			*tmp;

	if (tab->bytes >= tab->alloc_bytes)
		return ;
	tmp = MAL(t_byte, tab->bytes);
	if (tmp == NULL)
		return ;
	tab->alloc_bytes = tab->bytes;
	if (tab->data != NULL)
	{
		ft_memcpy(tmp, tab->data, tab->bytes);
		free(tab->data);
	}
	tab->data = tmp;
}
