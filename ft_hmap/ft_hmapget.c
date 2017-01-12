/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:33 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:18:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

t_hpair			ft_hmapget(t_hmap const *map, t_sub key)
{
	uint32_t		hash;
	t_h				*h;

	hash = map->hash(key);
	h = map->data[ABS(hash) % map->alloc_size];
	while (h != NULL && h->hash <= hash)
	{
		if (h->hash == hash && h->key_len == key.length
			&& memcmp(HMAP_H_KEY(h), key.str, key.length) == 0)
			return ((t_hpair){HMAP_H_KEY(h), h->data});
		h = h->next;
	}
	return ((t_hpair){NULL, NULL});
}
