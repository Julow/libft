/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 17:57:44 by juloo             #+#    #+#             */
/*   Updated: 2015/01/16 18:45:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_memswap(void *mem1, void *mem2, t_uint len)
{
	t_byte			tmp8;
	MEM_TYPE		tmp64;

	while (len >= sizeof(MEM_TYPE))
	{
		tmp64 = *((MEM_TYPE*)mem1);
		*((MEM_TYPE*)mem1) = *((MEM_TYPE*)mem2);
		*((MEM_TYPE*)mem2) = tmp64;
		mem1 += sizeof(MEM_TYPE);
		mem2 += sizeof(MEM_TYPE);
		len -= sizeof(MEM_TYPE);
	}
	while (len > 0)
	{
		tmp8 = *((t_byte*)mem1);
		*((t_byte*)mem1) = *((t_byte*)mem2);
		*((t_byte*)mem2) = tmp8;
		mem1++;
		mem2++;
		len--;
	}
}
