/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:44:30 by juloo             #+#    #+#             */
/*   Updated: 2015/04/29 13:22:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_insertsort(void **tab, int length, int (*cmp)())
{
	int				i;
	int				j;
	void			*tmp;

	i = -1;
	while (++i < length)
	{
		j = i;
		tmp = tab[i];
		while (j-- > 0)
		{
			if (cmp(tab[j], tmp) <= 0)
				break ;
			tab[j + 1] = tab[j];
		}
		j++;
		tab[j] = tmp;
	}
}
