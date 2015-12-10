/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:06:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

int				ft_memcmp(const void *s1, const void *s2, uint32_t n)
{
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
			return ((int)(*((uint8_t*)s1) - *((uint8_t*)s2)));
		s1++;
		s2++;
	}
	return (0);
}
