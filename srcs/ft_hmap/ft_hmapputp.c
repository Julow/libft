/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapputp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:23 by juloo             #+#    #+#             */
/*   Updated: 2015/05/03 23:05:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Put a pointer in the map with 'key'
** -
** Warning: If the key already exists in the map,
** the old data will be overwritten and not free
*/
void			ft_hmapputp(t_hmap *map, char const *key, void *data)
{
	const int		key_len = ft_strlen(key);
	t_h				*h;
	t_h				**tmp;

	h = (t_h*)malloc(sizeof(t_h) + key_len + 1);
	h->hash = map->hash(key, key_len);
	h->key_len = key_len;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = data;
	h->next = NULL;
	ft_memcpy(h->key, key, key_len + 1);
	tmp = map->data + (h->hash % map->size);
	while (*tmp != NULL)
		if ((*tmp)->hash == h->hash && (*tmp)->key_len == key_len
			&& ft_memcmp((*tmp)->key, key, key_len) == 0)
		{
			h->next = (*tmp)->next;
			free(*tmp);
			break ;
		}
	*tmp = h;
}
