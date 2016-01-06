/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:18:35 by juloo             #+#    #+#             */
/*   Updated: 2015/04/30 23:19:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define PIVOT		0

static void		check_pivot(void **tab, int length)
{
	void			*tmp;

	length >>= 2;
	tmp = tab[PIVOT];
	tab[PIVOT] = tab[length];
	tab[length] = tmp;
}

void			ft_quicksort(void **tab, int length, int (*cmp)())
{
	int				right;
	int				left;
	void			*tmp;

	if (length <= 4)
		return (ft_insertsort(tab, length, cmp));
	check_pivot(tab, length);
	right = length;
	left = 1;
	while (left < right)
		if (cmp(tab[left], tab[PIVOT]) >= 0)
		{
			tmp = tab[--right];
			tab[right] = tab[left];
			tab[left] = tmp;
		}
		else
			left++;
	tmp = tab[PIVOT];
	tab[PIVOT] = tab[left - 1];
	tab[left - 1] = tmp;
	if (left > 1)
		ft_quicksort(tab, left, cmp);
	if (left < (length - 1))
		ft_quicksort(tab + left, length - left, cmp);
}
