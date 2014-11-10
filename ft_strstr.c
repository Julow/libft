/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:21:20 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 12:21:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	int				i;
	int				j;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i + j] != s2[j] || s2[j] == '\0')
				break ;
			j++;
		}
		if (s2[j] == '\0')
			return (i + (char*)s1);
		i++;
	}
	return (NULL);
}
