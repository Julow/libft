/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:05:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

void			*ft_memset(void *b, int c, uint32_t len)
{
	MEM_TYPE		*bytes64;
	MEM_TYPE		value64;
	uint8_t			*bytes8;
	uint8_t			value8;

	value8 = (uint8_t)c;
	value64 = (MEM_TYPE)value8;
	value64 = (value64 << 8) | (MEM_TYPE)value8;
	value64 = (value64 << 16) | value64;
	value64 = (value64 << 32) | value64;
	bytes64 = (MEM_TYPE*)b;
	while (len >= sizeof(MEM_TYPE))
	{
		*(bytes64++) = value64;
		len -= sizeof(MEM_TYPE);
	}
	bytes8 = (uint8_t*)bytes64;
	while (len-- > 0)
		*(bytes8++) = value8;
	return (b);
}
