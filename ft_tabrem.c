/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:04:55 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:04:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabrem(t_tab *tab, int index, int n)
{
	if (index >= tab->length)
		return ;
	if (index + n > tab->length)
		n = tab->length - index;
	index *= tab->size;
	tab->length -= n;
	n *= tab->size;
	tab->bytes -= n;
	ft_memmove(tab->data + index, tab->data + index + n, tab->bytes - index);
}
