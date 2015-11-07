/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapkeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:55:42 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:57:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

int				ft_hmapkeys(t_hmap *map, char **dst, int max)
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
			dst[count++] = HMAP_H_KEY(h);
			h = h->next;
		}
	}
	return (count);
}
