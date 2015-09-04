/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 14:51:57 by juloo             #+#    #+#             */
/*   Updated: 2015/04/27 15:32:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_simplesort(void **tab, int length, int (*cmp)())
{
	int				i;
	int				max;
	void			*tmp;

	while (length-- > 0)
	{
		i = -1;
		max = length;
		while (++i < length)
			if (cmp(tab[i], tab[max]) > 0)
				max = i;
		if (max != length)
		{
			tmp = tab[max];
			tab[max] = tab[i];
			tab[i] = tmp;
		}
	}
}
