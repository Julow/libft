/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmaprem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:56:04 by juloo             #+#    #+#             */
/*   Updated: 2015/05/03 23:15:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove the data at 'key'
** -
** If 'f' is not NULL, 'f' is called with the data to remove
** Do nothing if 'key' is not found
*/
void			ft_hmaprem(t_hmap *map, char const *key, void (*f)(void*))
{
	const int		key_len = ft_strlen(key);
	int				hash;
	t_h				**h;
	t_h				*tmp;

	hash = map->hash(key, key_len);
	h = map->data + (h->hash % map->size);
	while (*h != NULL)
		if ((*h)->hash == hash && (*h)->key_len == key_len
			&& ft_memcmp((*h)->key, key, key_len) == 0)
		{
			tmp = *h;
			*h = tmp->next;
			f(tmp->data);
			free(tmp);
			break ;
		}
}
