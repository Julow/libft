/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapkeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:55:42 by juloo             #+#    #+#             */
/*   Updated: 2015/08/22 23:02:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"

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
			dst[count++] = h->key;
			h = h->next;
		}
	}
	return (count);
}
