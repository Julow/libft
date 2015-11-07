/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 18:47:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, t_uint len)
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
		*((t_byte*)tmp_dst) = *((t_byte*)tmp_src);
		tmp_dst++;
		tmp_src++;
		len--;
	}
	return (dst);
}
