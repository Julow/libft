/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 18:38:16 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/19 16:09:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"
#include <stdlib.h>

void			*ft_memdup(const void *src, uint32_t len)
{
	void			*dup;

	if ((dup = MALLOC(len)) == NULL)
		return (NULL);
	ft_memcpy(dup, src, len);
	return (dup);
}
