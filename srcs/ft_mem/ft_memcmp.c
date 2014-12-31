/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:06:42 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 15:06:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, t_uint n)
{
	while (n > 7)
	{
		if (*((t_ulong*)s1) != *((t_ulong*)s2))
			break ;
		s1 += 8;
		s2 += 8;
		n -= 8;
	}
	while (n-- > 0)
	{
		if (*((t_byte*)s1) != *((t_byte*)s2))
			return ((int)(*((t_byte*)s1) - *((t_byte*)s2)));
		s1++;
		s2++;
	}
	return (0);
}
