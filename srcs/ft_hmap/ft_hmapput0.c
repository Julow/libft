/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapput0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:13 by juloo             #+#    #+#             */
/*   Updated: 2015/05/03 23:09:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Put 'size' + 1 (0) bytes into the map with 'key'
** -
** Warning: If the key already exists in the map,
** the old data will be overrided and not free (if it's a pointer data)
** -
** Return a pointer to the data
*/
void			*ft_hmapput0(t_hmap *map, char const *key, int size)
{
	const int		key_len = ft_strlen(key);
	t_h				*h;
	t_h				**tmp;

	h = (t_h*)malloc(sizeof(t_h) + key_len + 1 + size + 1);
	h->hash = map->hash(key, key_len);
	h->key_len = key_len;
	h->key = ((char*)h) + sizeof(t_h);
	h->data = (void*)(h->key + key_len + 1);
	h->next = NULL;
	ft_memcpy(h->key, key, key_len + 1);
	ft_bzero(h->data, size + 1);
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
