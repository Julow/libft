/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:05:02 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:05:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_tabchr(t_tab *tab, const void *chr)
{
	int				i;

	i = -1;
	while (++i < tab->length)
		if (ft_memcmp(ft_tabget(tab, i), chr, tab->size) == 0)
			return (i);
	return (-1);
}
