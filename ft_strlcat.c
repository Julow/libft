/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:43:56 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 13:43:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			i2;

	i = 0;
	while (dest[i] != '\0')
		i++;
	i2 = 0;
	while (src[i2] != '\0' && (i + i2) < size)
	{
		dest[i + i2] = src[i2];
		i2++;
	}
	dest[i + i2] = '\0';
	return (i + i2);
}
