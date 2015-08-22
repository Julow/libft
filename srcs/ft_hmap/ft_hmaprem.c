/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmaprem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:04 by juloo             #+#    #+#             */
/*   Updated: 2015/08/22 22:59:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

void			ft_hmaprem(t_hmap *map, t_sub key, void (*f)(void*))
{
	int				hash;
	t_h				**h;
	t_h				*tmp;

	hash = map->hash(key);
	h = map->data + (hash % map->alloc_size);
	while (*h != NULL)
	{
		if ((*h)->hash == hash && (*h)->key_len == key.length
			&& ft_memcmp((*h)->key, key.str, key.length) == 0)
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
