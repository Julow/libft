/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 00:42:32 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

/*
** Return the number of byte that are equals in 's1' and 's2'
** Return 'n' if all bytes match
*/

uint32_t			ft_memstart(void const *s1, void const *s2, uint32_t n)
{
	uint32_t const	length = n;

	while (n > sizeof(MEM_TYPE))
	{
		if (*((MEM_TYPE*)s1) != *((MEM_TYPE*)s2))
			break ;
		s1 += sizeof(MEM_TYPE);
		s2 += sizeof(MEM_TYPE);
		n -= sizeof(MEM_TYPE);
	}
	while (n-- > 0)
	{
		if (*((uint8_t*)s1) != *((uint8_t*)s2))
			return (length - n);
		s1++;
		s2++;
	}
	return (length);
}
