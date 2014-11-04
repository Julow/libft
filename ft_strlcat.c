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
	size_t			length;
	size_t			i;

	length = 0;
	while (dst[length] != '\0')
		length++;
	i = 0;
	while (src[i] != '\0' && length < size)
	{
		dst[length] = src[i];
		length++;
		i++;
	}
	return (length);
}
