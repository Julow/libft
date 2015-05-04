/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapputp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:23 by juloo             #+#    #+#             */
/*   Updated: 2015/05/04 01:53:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

/*
** Put a pointer in the map with 'key'
** -
** Warning: If the key already exists in the map,
** the old data will be overwritten and not free
*/
void			ft_hmapputp(t_hmap *map, char const *key, void *data)
{
	const int		key_len = ft_strlen(key);
	t_h				*h;

	h = (t_h*)malloc(sizeof(t_h) + key_len + 1);
	h->hash = map->hash(key, key_len);
	h->key_len = key_len;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = data;
	h->next = NULL;
	ft_memcpy(h->key, key, key_len + 1);
	hmap_puth(map, h);
}
