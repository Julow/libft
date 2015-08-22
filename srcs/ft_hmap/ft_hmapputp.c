/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapputp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:23 by juloo             #+#    #+#             */
/*   Updated: 2015/08/22 22:59:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

void			ft_hmapputp(t_hmap *map, t_sub key, void *data)
{
	t_h				*h;

	h = (t_h*)malloc(sizeof(t_h) + key.length + 1);
	h->hash = map->hash(key);
	h->key_len = key.length;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = data;
	h->next = NULL;
	ft_memcpy(h->key, key.str, key.length + 1);
	hmap_puth(map, h);
}
