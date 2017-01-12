/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmaprem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:04 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:18:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"
#include <stdlib.h>

void			ft_hmaprem(t_hmap *map, t_sub key, void (*f)(void*))
{
	uint32_t		hash;
	t_h				**h;
	t_h				*tmp;

	hash = map->hash(key);
	h = map->data + (hash % map->alloc_size);
	while (*h != NULL)
	{
		if ((*h)->hash == hash && (*h)->key_len == key.length
			&& memcmp(HMAP_H_KEY(*h), key.str, key.length) == 0)
		{
			tmp = *h;
			*h = tmp->next;
			if (f != NULL)
				f(tmp->data);
			free(tmp);
			map->size--;
			break ;
		}
		h = &((*h)->next);
	}
}
