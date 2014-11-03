/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:06:42 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 15:06:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1Bytes;
	unsigned char	*s2Bytes;

	s1Bytes = (unsigned char*)s1;
	s2Bytes = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1Bytes[i] != s2Bytes[i])
			return ((int)(s1Bytes[i] - s2Bytes[i]));
		i++;
	}
	return (0);
}
