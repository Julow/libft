/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

void			*ft_memcpy(void *dst, const void *src, uint32_t len)
{
	void			*tmp_dst;
	void			*tmp_src;

	if (src == dst)
		return (dst);
	tmp_dst = dst;
	tmp_src = (void*)src;
	while (len >= sizeof(MEM_TYPE))
	{
		*((MEM_TYPE*)tmp_dst) = *((MEM_TYPE*)tmp_src);
		tmp_dst += sizeof(MEM_TYPE);
		tmp_src += sizeof(MEM_TYPE);
		len -= sizeof(MEM_TYPE);
	}
	while (len > 0)
	{
		*((uint8_t*)tmp_dst) = *((uint8_t*)tmp_src);
		tmp_dst++;
		tmp_src++;
		len--;
	}
	return (dst);
}
