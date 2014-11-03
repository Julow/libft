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

void			*ft_memmove(void *dst, void *src, size_t len)
{
	size_t			i;
	char			*dst_bytes;
	char			*src_bytes;

	if (dst == src || len == 0)
		return (dst);
	dst_bytes = (char*)dst;
	src_bytes = (char*)src;
	i = 0;
	while (i < len)
	{
		dst_bytes[i] = src_bytes[i];
		i++;
	}
	return (dst);
}
