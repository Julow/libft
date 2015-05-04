/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:45:03 by juloo             #+#    #+#             */
/*   Updated: 2015/05/04 01:50:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

/*
** Init a hmap
*/
void			ft_hmapini(t_hmap *map, int size, int (*h)(char const*, int))
{
	map->size = 0;
	map->alloc_size = size;
	map->data = MAL(t_h*, size);
	ft_bzero(map->data, S(t_h*, size));
	map->hash = h;
}
