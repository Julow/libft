/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:59:42 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 11:59:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			*ft_strdup(char *src)
{
	size_t			i;
	size_t			len;
	char			*dst;

	len = ft_strlen(src);
	dst = (char*)malloc(sizeof(char*) * (len + 1));
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
