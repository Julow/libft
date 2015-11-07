/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:55:57 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:57:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"
#include <stdlib.h>

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
	free(map);
}
