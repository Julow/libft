/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:33 by juloo             #+#    #+#             */
/*   Updated: 2015/09/23 14:03:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"

void			*ft_hmapget(t_hmap const *map, t_sub key)
{
	t_uint			hash;
	t_h				*h;

	hash = map->hash(key);
	h = map->data[ABS(hash) % map->alloc_size];
	while (h != NULL && h->hash <= hash)
	{
		if (h->hash == hash && h->key_len == key.length
			&& ft_memcmp(HMAP_H_KEY(h), key.str, key.length) == 0)
			return (h->data);
		h = h->next;
	}
	return (NULL);
}
