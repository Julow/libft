/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 00:42:32 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 00:42:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy as many time as necessary 'src' to fill 'dst'
*/
void			ft_memfill(void *dst, void const *src, int size, int dst_size)
{
	int				i;

	ft_memcpy(dst, src, MIN(size, dst_size));
	i = size;
	while (i < dst_size)
	{
		ft_memcpy(dst + i, dst, MIN(dst_size - i, i));
		i += i;
	}
}
