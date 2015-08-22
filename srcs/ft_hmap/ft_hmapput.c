/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:19 by juloo             #+#    #+#             */
/*   Updated: 2015/08/22 23:26:18 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_internal.h"

void			*ft_hmapput(t_hmap *map, t_sub key, void const *data, int size)
{
	t_h				*h;

	h = (t_h*)ft_emalloc(sizeof(t_h) + key.length + 1 + size + 1);
	h->hash = map->hash(key);
	h->key_len = key.length;
	h->data = (void*)(HMAP_H_KEY(h) + key.length + 1);
	h->next = NULL;
	ft_memcpy(HMAP_H_KEY(h), key.str, key.length);
	HMAP_H_KEY(h)[key.length] = '\0';
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
