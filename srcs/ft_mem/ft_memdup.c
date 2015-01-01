/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 18:38:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/01 18:38:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memdup(const void *src, t_uint len)
{
	void			*dup;

	if ((dup = MAL(t_byte, len)) == NULL)
		return (NULL);
	ft_memcpy(dup, src, len);
	return (dup);
}
