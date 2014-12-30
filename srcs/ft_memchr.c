/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:59:33 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 14:59:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, t_uint n)
{
	t_uchar			*bytes;
	t_uchar			stop;

	if (s == NULL)
		return (NULL);
	stop = (t_uchar)(t_uint)c;
	bytes = (t_uchar*)s;
	while (n-- > 0)
	{
		if (*(bytes) == stop)
			return (bytes);
		bytes++;
	}
	return (NULL);
}
