/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 12:23:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/01 12:23:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnchr(const char *s, char c, int len)
{
	while (len-- > 0)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0' && *s == '\0')
		return ((char*)s);
	return (NULL);
}
