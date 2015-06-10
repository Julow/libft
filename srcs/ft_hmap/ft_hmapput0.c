/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapput0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:13 by juloo             #+#    #+#             */
/*   Updated: 2015/06/11 01:42:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

/*
** Put 'size' + 1 (0) bytes into the map with 'key'
** -
** Warning: If the key already exists in the map,
** the old data will be overrided and not free (if it's a pointer data)
** -
** Return a pointer to the data
*/
void			*ft_hmapput0(t_hmap *map, t_sub key, int size)
{
	t_h				*h;

	h = (t_h*)malloc(sizeof(t_h) + key.length + 1 + size + 1);
	h->hash = map->hash(key);
	h->key_len = key.length;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = (void*)(h->key + key.length + 1);
	h->next = NULL;
	ft_memcpy(h->key, key.str, key.length + 1);
	ft_bzero(h->data, size + 1);
	hmap_puth(map, h);
	return (h->data);
}
