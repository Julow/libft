/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 17:57:44 by juloo             #+#    #+#             */
/*   Updated: 2014/12/23 17:57:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_memswap(void *mem1, void *mem2, t_uint len)
{
	t_byte			tmp8;
	t_ulong			tmp64;

	while (len >= 8)
	{
		tmp64 = *((t_ulong*)mem1);
		*((t_ulong*)mem1) = *((t_ulong*)mem2);
		*((t_ulong*)mem2) = tmp64;
		mem1 = VOIDADD(mem1, 8);
		mem2 = VOIDADD(mem2, 8);
		len -= 8;
	}
	while (len > 0)
	{
		tmp8 = *((t_byte*)mem1);
		*((t_byte*)mem1) = *((t_byte*)mem2);
		*((t_byte*)mem2) = tmp8;
		VOIDPP(mem1);
		VOIDPP(mem2);
		len--;
	}
}
