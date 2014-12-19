/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:35:28 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:35:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	t_byte			*dst8;
	t_ulong			*dst64;
	t_byte			*src8;
	t_ulong			*src64;

	if (src == dst)
		return (dst);
	else if (src > dst || dst >= (src + len))
		return (ft_memcpy(dst, src, len));
	dst64 = (t_ulong*)(dst + len - 1);
	src64 = (t_ulong*)(src + len - 1);
	while (len > 7)
	{
		*(dst64--) = *(src64--);
		len -= 8;
	}
	dst8 = (t_byte*)dst64;
	src8 = (t_byte*)src64;
	while (len-- > 0)
		*(dst8--) = *(src8--);
	return (dst);
}
