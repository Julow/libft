/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:59:33 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 14:59:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	stop;
	unsigned char	*strBytes;

	stop = (unsigned char)c;
	strBytes = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (strBytes[i] == stop)
			return strBytes + i;
		i++;
	}
	return (NULL);
}
