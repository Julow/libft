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

t_uint			ft_strlcat(char *dst, const char *src, t_uint size)
{
	t_uint			length;
	t_uint			i;

	length = 0;
	while (dst[length] != '\0' && length < size)
		length++;
	i = 0;
	while (src[i] != '\0' && (length + i) < size)
	{
		dst[length + i] = src[i];
		i++;
	}
	if ((length + i) < size)
		dst[length + i] = '\0';
	else if (length < size)
		dst[length + i - 1] = '\0';
	return (length + ft_strlen(src));
}
