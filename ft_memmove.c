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
	char			*dst_bytes;
	char			*src_bytes;

	if (dst >= src || len == 0)
		return (ft_memcpy(dst, src, len));
	dst_bytes = (char*)dst;
	src_bytes = (char*)src;
	while (len >= 0)
	{
		dst_bytes[len] = src_bytes[len];
		len--;
	}
	return (dst);
}
