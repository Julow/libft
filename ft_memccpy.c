/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:55:32 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:55:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	stop;
	unsigned char	*dst_bytes;
	unsigned char	*src_bytes;

	stop = (unsigned char)c;
	dst_bytes = (unsigned char*)dst;
	src_bytes = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst_bytes[i] = src_bytes[i];
		if (src_bytes[i] == stop)
			return src_bytes + i + 1;
		i++;
	}
	return (NULL);
}
