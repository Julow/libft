/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_djb2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:50:54 by juloo             #+#    #+#             */
/*   Updated: 2016/01/18 18:18:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

uint32_t		ft_djb2(t_sub sub)
{
	uint32_t		hash;
	uint32_t		i;

	hash = 5381;
	i = 0;
	while (i < sub.length)
		hash = ((hash << 5) + hash) + sub.str[i++];
	return (hash);
}
