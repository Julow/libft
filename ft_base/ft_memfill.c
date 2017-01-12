/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 00:42:32 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:18:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

/*
** Copy as many time as necessary 'src' to fill 'dst'
*/

void			ft_memfill(void *dst, void const *src, int size, int dst_size)
{
	int				i;

	memcpy(dst, src, MIN(size, dst_size));
	i = size;
	while (i < dst_size)
	{
		memcpy(dst + i, dst, MIN(dst_size - i, i));
		i += i;
	}
}
