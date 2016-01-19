/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:07:51 by juloo             #+#    #+#             */
/*   Updated: 2016/01/19 16:12:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

t_hmap			*ft_hmapnew(int size, uint32_t (*h)(t_sub))
{
	t_hmap			*map;

	map = (t_hmap*)MALLOC(sizeof(t_hmap) + S(t_h*, size));
	*map = (t_hmap){0, size, ((void*)map) + sizeof(t_hmap), h};
	ft_bzero(map->data, S(t_h*, size));
	return (map);
}
