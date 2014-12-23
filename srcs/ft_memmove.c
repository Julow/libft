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

void			*ft_memmove(void *dst, const void *src, t_uint len)
{
	void			*tmp_dst;
	void			*tmp_src;

	if (src >= dst || dst >= (src + len))
		return (ft_memcpy(dst, src, len));
	tmp_dst = dst + len - 1;
	tmp_src = ((void*)src) + len - 1;
	while (len > 7)
	{
		*((t_ulong*)tmp_dst) = *((t_ulong*)tmp_src);
		tmp_dst = VOIDADD(tmp_dst, -8);
		tmp_src = VOIDADD(tmp_src, -8);
		len -= 8;
	}
	while (len > 0)
	{
		*((t_byte*)tmp_dst) = *((t_byte*)tmp_src);
		VOIDMM(tmp_dst);
		VOIDMM(tmp_src);
		len--;
	}
	return (dst);
}
