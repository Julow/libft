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

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst_bytes;
	char			*src_bytes;

	dst_bytes = (char*)dst;
	src_bytes = (char*)src;
	if (dst != src)
	{
		if (src_bytes < dst_bytes && dst_bytes < (src_bytes + len))
		{
			dst_bytes = dst_bytes + len - 1;
			src_bytes = src_bytes + len - 1;
			while (len-- > 0)
				*(dst_bytes--) = *(src_bytes--);
		}
		else
		{
			while (len-- > 0)
				*(dst_bytes++) = *(src_bytes++);
		}
	}
	return (dst);
}
