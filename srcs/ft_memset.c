/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:05:54 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:05:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	value;

	value = (unsigned char)c;
	i = 0;
	while (i < len && b != NULL)
	{
		*(char*)(b + i) = value;
		i++;
	}
	return (b);
}
