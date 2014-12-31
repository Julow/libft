/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 15:03:31 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/19 15:03:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong			*ft_memalign(void *mem, const void *data, t_uint *len)
{
	t_byte			*bytes8;
	t_byte			*src8;
	t_ulong			n;

	bytes8 = (t_byte*)mem;
	src8 = (t_byte*)data;
	n = MIN(*len, (t_ulong)mem & 3);
	*len -= n;
	while (n-- > 0)
		*(bytes8++) = *(src8++);
	return ((t_ulong*)bytes8);
}
