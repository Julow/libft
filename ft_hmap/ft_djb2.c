/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_djb2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:50:54 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:57:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmap_internal.h"

t_uint			ft_djb2(t_sub sub)
{
	t_uint			hash;
	int				i;

	hash = 5381;
	i = -1;
	while (++i < sub.length)
		hash = ((hash << 5) + hash) + sub.str[i];
	return (hash);
}
