/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:05:30 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:05:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabswap(t_tab *tab, int i1, int i2)
{
	char			tmp[tab->size];
	t_byte			*data1;
	t_byte			*data2;

	if (i1 >= tab->length || i2 >= tab->length)
		ft_tabext(tab, ((i1 > i2) ? i1 : i2) - tab->length + 1);
	data1 = ft_tabget(tab, i1);
	data2 = ft_tabget(tab, i2);
	ft_memcpy(tmp, data1, tab->size);
	ft_memmove(data1, data2, tab->size);
	ft_memcpy(data2, tmp, tab->size);
}
