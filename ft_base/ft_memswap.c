/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 17:57:44 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

void			ft_memswap(void *mem1, void *mem2, uint32_t len)
{
	uint8_t			tmp8;
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
		tmp8 = *((uint8_t*)mem1);
		*((uint8_t*)mem1) = *((uint8_t*)mem2);
		*((uint8_t*)mem2) = tmp8;
		mem1++;
		mem2++;
		len--;
	}
}
