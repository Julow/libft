/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_puth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 01:50:44 by juloo             #+#    #+#             */
/*   Updated: 2015/08/22 23:26:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

void			hmap_puth(t_hmap *map, t_h *h)
{
	t_h				**tmp;

	tmp = map->data + (ABS(h->hash) % map->alloc_size);
	while (*tmp != NULL)
	{
		if ((*tmp)->hash == h->hash && (*tmp)->key_len == h->key_len
			&& ft_memcmp(HMAP_H_KEY(*tmp), HMAP_H_KEY(h), h->key_len) == 0)
		{
			h->next = (*tmp)->next;
			free(*tmp);
			map->size--;
			break ;
		}
		tmp = &((*tmp)->next);
	}
	*tmp = h;
	map->size++;
}
