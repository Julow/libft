/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:05:54 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:05:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	t_ulong			*bytes64;
	t_ulong			value64;
	t_byte			*bytes8;
	t_byte			value8;

	value8 = (t_byte)c;
	value64 = (t_ulong)value8;
	value64 = (value64 << 8) | (t_ulong)value8;
	value64 = (value64 << 16) | value64;
	value64 = (value64 << 32) | value64;
	bytes64 = (t_ulong*)b;
	while (len > 7)
	{
		*(bytes64++) = value64;
		len -= 8;
	}
	bytes8 = (t_byte*)bytes64;
	while (len-- > 0)
		*(bytes8++) = value8;
	return (b);
}
