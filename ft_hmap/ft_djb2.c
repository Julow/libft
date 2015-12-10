/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_djb2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:50:54 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:20:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

uint32_t		ft_djb2(t_sub sub)
{
	uint32_t		hash;
	int				i;

	hash = 5381;
	i = -1;
	while (++i < sub.length)
		hash = ((hash << 5) + hash) + sub.str[i];
	return (hash);
}
