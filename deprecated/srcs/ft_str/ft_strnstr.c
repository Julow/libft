/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:28:32 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 12:28:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, t_uint n)
{
	t_uint			i;
	t_uint			j;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s2[j] != '\0' && (i + j) < n)
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
