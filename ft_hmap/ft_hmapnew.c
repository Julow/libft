/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:07:51 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:20:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

t_hmap			*ft_hmapnew(int size, uint32_t (*h)(t_sub))
{
	t_hmap			*map;

	map = (t_hmap*)MALLOC(sizeof(t_hmap) + S(t_h*, size));
	*map = (t_hmap){0, size, ((void*)map) + sizeof(t_hmap), h};
	memset(map->data, 0, S(t_h*, size));
	return (map);
}
