/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapdatas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:55:49 by juloo             #+#    #+#             */
/*   Updated: 2015/06/11 01:43:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"

/*
** Extract datas from the map
** -
** The array 'dst' is filled with pointers to each datas of the map
** -
** Warning: The array 'dst' must have enougth space
** -
** Return the number of extracted datas
*/
int				ft_hmapdatas(t_hmap *map, void **dst)
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
			dst[count++] = h->data;
			h = h->next;
		}
	}
	return (count);
}
