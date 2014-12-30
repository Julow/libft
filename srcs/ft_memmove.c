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
	void			*tmp_dst;
	void			*tmp_src;

	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	tmp_dst = dst + len;
	tmp_src = ((void*)src) + len;
	while (len > 7)
	{
		tmp_dst -= 8;
		tmp_src -= 8;
		*((t_ulong*)tmp_dst) = *((t_ulong*)tmp_src);
		len -= 8;
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
