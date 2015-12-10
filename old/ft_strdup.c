/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:59:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strdup(const char *src)
{
	uint32_t			len;
	char			*dst;

	len = ft_strlen(src);
	dst = MAL(char, len + 1);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, len + 1);
	return (dst);
}
