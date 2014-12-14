/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabaddn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:04:39 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:04:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabaddn(t_tab *tab, t_byte *add, int n)
{
	const int		bytes = tab->size * n;

	ft_tabext(tab, n);
	ft_memmove(tab->data + tab->bytes, add, bytes);
	tab->length += n;
	tab->bytes += bytes;
}
