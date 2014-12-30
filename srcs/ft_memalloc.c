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

void			*ft_memalloc(t_uint size)
{
	void			*alloc;

	if (size == 0)
		return (NULL);
	alloc = (void*)malloc(size);
	if (alloc)
		ft_bzero(alloc, size);
	return (alloc);
}
