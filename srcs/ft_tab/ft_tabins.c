/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:04:47 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:04:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabins(t_tab *tab, const void *ins, int index, int n)
{
	if (index >= tab->length)
	{
		ft_tabset(tab, ins, index, n);
		return ;
	}
	if (!ft_tabext(tab, n))
		return ;
	index *= tab->size;
	tab->length += n;
	n *= tab->size;
	ft_memmove(tab->data + index + n, tab->data + index, tab->bytes - index);
	ft_memmove(tab->data + index, ins, n);
	tab->bytes += n;
}
