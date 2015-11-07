/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:35:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 18:47:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, t_uint len)
{
	void			*tmp_dst;
	void			*tmp_src;

	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	tmp_dst = dst + len;
	tmp_src = ((void*)src) + len;
	while (len >= sizeof(MEM_TYPE))
	{
		tmp_dst -= sizeof(MEM_TYPE);
		tmp_src -= sizeof(MEM_TYPE);
		*((MEM_TYPE*)tmp_dst) = *((MEM_TYPE*)tmp_src);
		len -= sizeof(MEM_TYPE);
	}
	while (len > 0)
	{
		tmp_dst--;
		tmp_src--;
		*((t_byte*)tmp_dst) = *((t_byte*)tmp_src);
		len--;
	}
	return (dst);
}
