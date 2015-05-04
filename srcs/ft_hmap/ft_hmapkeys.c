/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapkeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:55:42 by juloo             #+#    #+#             */
/*   Updated: 2015/05/04 02:16:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

/*
** Extract keys from the map
** -
** The array 'dst' is filled with pointers to each keys of the map
** -
** Warning: The array 'dst' must have enougth space
** Warning: Keys must not be modified
** -
** Return the number of extracted keys
*/
int				ft_hmapkeys(t_hmap *map, char **dst)
{
	int				count;
	int				i;
	t_h				*h;

	count = 0;
	i = -1;
	while (++i < map->alloc_size)
	{
		h = map->data[i];
		while (h != NULL)
		{
			dst[count++] = h->key;
			h = h->next;
		}
	}
	return (count);
}
