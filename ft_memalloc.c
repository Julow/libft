/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:05:34 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 14:05:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*alloc;

	alloc = (unsigned char*)malloc(size);
	if (alloc)
	{
		i = 0;
		while (i < size)
		{
			alloc[i] = 0;
			i++;
		}
	}
	return (alloc);
}
