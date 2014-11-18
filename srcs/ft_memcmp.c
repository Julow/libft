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

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_bytes;
	unsigned char	*s2_bytes;

	s1_bytes = (unsigned char*)s1;
	s2_bytes = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1_bytes[i] != s2_bytes[i])
			return ((int)(s1_bytes[i] - s2_bytes[i]));
		i++;
	}
	return (0);
}
