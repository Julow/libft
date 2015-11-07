/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapdatas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:55:49 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:57:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

int				ft_hmapdatas(t_hmap *map, void **dst, int max)
{
	int				count;
	int				i;
	t_h				*h;

	if (max < 0)
		max = map->size;
	count = 0;
	i = -1;
	while (++i < map->alloc_size)
	{
		h = map->data[i];
		while (h != NULL && count < max)
		{
			dst[count++] = h->data;
			h = h->next;
		}
	}
	return (count);
}
