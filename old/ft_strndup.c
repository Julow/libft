/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 18:34:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/01 18:34:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strndup(const char *src, t_uint len)
{
	char			*dup;

	if ((dup = MAL(char, len + 1)) == NULL)
		return (NULL);
	ft_memcpy(dup, src, S(char, len));
	dup[len] = '\0';
	return (dup);
}
