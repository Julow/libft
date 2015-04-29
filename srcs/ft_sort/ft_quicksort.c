/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:18:35 by juloo             #+#    #+#             */
/*   Updated: 2015/04/29 23:16:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_quicksort(void **tab, int length, int (*cmp)())
{
	int				pivot;
	int				right;
	int				left;
	void			*tmp;

	if (length <= 3)
		return (ft_bubblesort(tab, length, cmp));
	pivot = length / 2;
	right = pivot;
	left = pivot;
	while (true)
	{
		while (right < length && cmp(tab[right], tab[pivot]) >= 0)
			right++;
		while (left >= 0 && cmp(tab[left], tab[pivot]) <= 0)
			left--;
		if (left < 0)
		{
			if (right >= length)
				break ;
			tmp = tab[pivot];
			tab[pivot] = tab[right];
			tab[right] = tab[++pivot];
			tab[pivot] = tmp;
		}
		else if (right >= length)
		{
			tmp = tab[pivot];
			tab[pivot] = tab[left];
			tab[left] = tab[--pivot];
			tab[pivot] = tmp;
		}
		else
		{
			tmp = tab[right];
			tab[right] = tab[left];
			tab[left] = tmp;
		}
	}
	if (pivot > 0)
		ft_quicksort(tab, pivot, cmp);
	if ((pivot + 1) <= length)
		ft_quicksort(tab + pivot, length - pivot, cmp);
}
