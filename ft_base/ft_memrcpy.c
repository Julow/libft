/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:21:04 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

void			*ft_memrcpy(void *dst, const void *src, uint32_t len)
{
	void			*tmp_dst;
	void			*tmp_src;

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
		*((uint8_t*)tmp_dst) = *((uint8_t*)tmp_src);
		len--;
	}
	return (dst);
}
