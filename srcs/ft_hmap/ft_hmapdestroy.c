/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:55:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/11 01:42:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

/*
** Destroy the map
** -
** If 'f' is not NULL, 'f' is call for each datas
** The pointer 'map' is not free
*/
void			ft_hmapdestroy(t_hmap *map, void (*f)(void*))
{
	t_h				*h;
	t_h				*tmp;
	int				i;

	i = -1;
	while (++i < map->alloc_size)
	{
		h = map->data[i];
		while (h != NULL)
		{
			if (f != NULL)
				f(h->data);
			tmp = h;
			h = h->next;
			free(tmp);
		}
	}
	free(map->data);
	map->size = 0;
	map->alloc_size = 0;
	map->data = NULL;
}
