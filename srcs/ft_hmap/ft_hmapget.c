/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:33 by juloo             #+#    #+#             */
/*   Updated: 2015/05/03 23:00:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the data at 'key'
** Return NULL if not found
*/
void			*ft_hmapget(t_hmap *map, char const *key)
{
	const int		key_len = ft_strlen(key);
	int				hash;
	t_h				*h;

	hash = map->hash(key, key_len);
	h = map->data[hash % map->alloc_size];
	while (h != NULL)
	{
		if (h->hash == hash && h->key_len == key_len
			&& ft_memcmp(h->key, key, key_len) == 0)
			return (h->data);
		h = h->tmp;
	}
	return (NULL);
}
