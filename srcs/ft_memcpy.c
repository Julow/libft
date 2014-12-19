/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:34 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:20:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte			*dst8;
	t_ulong			*dst64;
	t_byte			*src8;
	t_ulong			*src64;

	dst64 = (t_ulong*)dst;
	src64 = (t_ulong*)src;
	while (n > 7)
	{
		*(dst64++) = *(src64++);
		n -= 8;
	}
	dst8 = (t_byte*)dst64;
	src8 = (t_byte*)src64;
	while (n-- > 0)
		*(dst8++) = *(src8++);
	return (dst);
}
