/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:19 by juloo             #+#    #+#             */
/*   Updated: 2015/06/11 01:42:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

/*
** Put a copy of 'data' (with a size of 'size') into the map with 'key'
** -
** 'size' bytes of 'data' + a '0' byte are copied into the map
** -
** Warning: If the key already exists in the map,
** the old data will be overwritten and not free (if it's a pointer data)
** -
** Return a pointer to the copy of 'data'
*/
void			*ft_hmapput(t_hmap *map, t_sub key, void const *d, int l)
{
	t_h				*h;

	h = (t_h*)malloc(sizeof(t_h) + key.length + 1 + l + 1);
	h->hash = map->hash(key);
	h->key_len = key.length;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = (void*)(h->key + key.length + 1);
	h->next = NULL;
	ft_memcpy(h->key, key.str, key.length + 1);
	ft_memcpy(h->data, d, l);
	((char*)h->data)[l] = '\0';
	hmap_puth(map, h);
	return (h->data);
}
