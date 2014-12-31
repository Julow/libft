/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:04:44 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:04:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabset(t_tab *tab, const void *set, int index, int n)
{
	if ((index + n) > tab->length)
	{
		if (ft_tabext(tab, index + n - tab->length))
		{
			tab->length += index + n - tab->length;
			tab->bytes = tab->length * tab->size;
		}
		else
			n = tab->length - index;
	}
	ft_memmove(tab->data + (index * tab->size), set, n * tab->size);
}
