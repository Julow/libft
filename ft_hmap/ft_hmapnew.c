/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:07:51 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:57:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

t_hmap			*ft_hmapnew(int size, t_uint (*h)(t_sub))
{
	t_hmap			*map;

	map = (t_hmap*)ft_emalloc(sizeof(t_hmap) + S(t_h*, size));
	*map = (t_hmap){0, size, ((void*)map) + sizeof(t_hmap), h};
	ft_bzero(map->data, S(t_h*, size));
	return (map);
}