/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:25:22 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 13:25:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			search;

	search = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == search)
			return (i + (char*)s);
		i++;
	}
	if (search == '\0')
		return (i + (char*)s);
	return (NULL);
}
