/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:19 by juloo             #+#    #+#             */
/*   Updated: 2015/08/22 22:59:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

void			*ft_hmapput(t_hmap *map, t_sub key, void const *data, int size)
{
	t_h				*h;

	h = (t_h*)malloc(sizeof(t_h) + key.length + 1 + size + 1);
	h->hash = map->hash(key);
	h->key_len = key.length;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = (void*)(h->key + key.length + 1);
	h->next = NULL;
	ft_memcpy(h->key, key.str, key.length);
	h->key[key.length] = '\0';
	if (data != NULL)
	{
		ft_memcpy(h->data, data, size);
		((char*)h->data)[size] = '\0';
	}
	else
		ft_bzero(h->data, size + 1);
	hmap_puth(map, h);
	return (h->data);
}
