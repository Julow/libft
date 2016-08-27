/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 17:12:31 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 17:25:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

static void		insertsort(t_sort_data *d, uint32_t length)
{
	uint32_t		i;
	uint32_t		j;

	i = 1;
	while (i < length)
	{
		j = i;
		while (j > 0 && d->cmp(d->data, j - 1, j) > 0)
		{
			d->swap(d->data, j - 1, j);
			j--;
		}
		i++;
	}
}

static uint32_t	quicksort_partition(t_sort_data *d, uint32_t lo, uint32_t hi)
{
	uint32_t		pivot;

	d->swap(d->data, (hi - lo) / 2 + lo, hi);
	pivot = hi;
	hi--;
	while (true)
	{
		while (lo < hi && d->cmp(d->data, lo, pivot) < 0)
			lo++;
		while (lo < hi && d->cmp(d->data, hi, pivot) > 0)
			hi--;
		if (lo >= hi)
			break ;
		d->swap(d->data, lo, hi);
		lo++;
		hi--;
	}
	return (lo);
}

static void		quicksort(t_sort_data *d, uint32_t lo, uint32_t hi)
{
	uint32_t		tmp;

	if ((hi - lo) <= 8)
		return ;
	tmp = quicksort_partition(d, lo, hi);
	if (tmp > (lo + 1))
		quicksort(d, lo, tmp - 1);
	if ((tmp + 1) < hi)
		quicksort(d, tmp + 1, hi);
}

void			ft_sort(void *data, uint32_t length,
					int (*cmp)(void const *data, uint32_t a, uint32_t b),
					void (*swap)(void *data, uint32_t a, uint32_t b))
{
	t_sort_data		d;

	if (length <= 1)
		return ;
	d = (t_sort_data){data, cmp, swap};
	quicksort(&d, 0, length - 1);
	insertsort(&d, length);
}
