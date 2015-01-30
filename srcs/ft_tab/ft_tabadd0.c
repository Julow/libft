/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 08:10:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/30 21:12:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_tabadd0(t_tab *tab)
{
	void			*pos;

	if (!ft_tabext(tab, 1))
		return (NULL);
	pos = tab->data + tab->bytes;
	tab->length++;
	tab->bytes += tab->size;
	ft_bzero(pos, tab->size);
	return (pos);
}
