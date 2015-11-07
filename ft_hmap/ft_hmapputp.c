/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapputp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:23 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:57:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

t_hpair			ft_hmapputp(t_hmap *map, t_sub key, void *data)
{
	t_h				*h;

	h = (t_h*)ft_emalloc(sizeof(t_h) + key.length + 1);
	h->hash = map->hash(key);
	h->key_len = key.length;
	h->data = data;
	h->next = NULL;
	ft_memcpy(HMAP_H_KEY(h), key.str, key.length + 1);
	hmap_puth(map, h);
	return ((t_hpair){HMAP_H_KEY(h), h->data});
}
