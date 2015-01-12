/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabaddn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:04:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:30:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_tabaddn(t_tab *tab, const void *add, int n)
{
	const int		bytes = tab->size * n;

	if (!ft_tabext(tab, n))
		return ;
	ft_memmove(tab->data + tab->bytes, add, bytes);
	tab->length += n;
	tab->bytes += bytes;
}
