/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/11 01:42:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"

/*
** Return the data at 'key'
** Return NULL if not found
*/
void			*ft_hmapget(t_hmap *map, t_sub key)
{
	int				hash;
	t_h				*h;

	hash = map->hash(key);
	h = map->data[hash % map->alloc_size];
	while (h != NULL)
	{
		if (h->hash == hash && h->key_len == key.length
			&& ft_memcmp(h->key, key.str, key.length) == 0)
			return (h->data);
		h = h->next;
	}
	return (NULL);
}
