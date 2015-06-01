/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:19 by juloo             #+#    #+#             */
/*   Updated: 2015/06/01 18:15:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void			*ft_hmapput(t_hmap *map, char const *key, void const *d, int l)
{
	const int		key_len = ft_strlen(key);
	t_h				*h;

	h = (t_h*)malloc(sizeof(t_h) + key_len + 1 + l + 1);
	h->hash = map->hash(key, key_len);
	h->key_len = key_len;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = (void*)(h->key + key_len + 1);
	h->next = NULL;
	ft_memcpy(h->key, key, key_len + 1);
	ft_memcpy(h->data, d, l);
	((char*)h->data)[l] = '\0';
	hmap_puth(map, h);
	return (h->data);
}
