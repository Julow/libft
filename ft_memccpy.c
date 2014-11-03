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

#include "ft.h"

void			*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	stop;

	stop = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == c)
			return src + i + 1;
		i++;
	}
	return (NULL);
}
