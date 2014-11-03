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
	unsigned char	*dstBytes;
	unsigned char	*srcBytes;

	stop = (unsigned char)c;
	dstBytes = (unsigned char*)dst;
	srcBytes = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dstBytes[i] = srcBytes[i];
		if (srcBytes[i] == stop)
			return srcBytes + i + 1;
		i++;
	}
	return (NULL);
}
