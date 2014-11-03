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

#include "ft.h"

void			*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	void			o[n];

	i = 0;
	while (i < n)
	{
		o[i] = dst[i];
		dst[i] = src[i];
		i++;
	}
	return (o);
}
