/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:34 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:20:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t len)
{
	void			*tmp_dst;
	void			*tmp_src;

	if (src == dst)
		return (dst);
	tmp_dst = dst;
	tmp_src = (void*)src;
	while (len > 7)
	{
		*((t_ulong*)tmp_dst) = *((t_ulong*)tmp_src);
		tmp_dst = VOIDADD(tmp_dst, 8);
		tmp_src = VOIDADD(tmp_src, 8);
		len -= 8;
	}
	while (len > 0)
	{
		*((t_byte*)tmp_dst) = *((t_byte*)tmp_src);
		VOIDPP(tmp_dst);
		VOIDPP(tmp_src);
		len--;
	}
	return (dst);
}
