/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:06:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 18:47:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, t_uint n)
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
		if (*((t_byte*)s1) != *((t_byte*)s2))
			return ((int)(*((t_byte*)s1) - *((t_byte*)s2)));
		s1++;
		s2++;
	}
	return (0);
}
