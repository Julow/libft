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

#include "ft.h"

void			*ft_memmove(void *dst, void *src, size_t len)
{
	size_t			i;
	void			o[len];

	i = 0;
	while (i < len)
	{
		o[i] = dst[i];
		dst[i] = src[i];
		i++;
	}
	return o;
}
