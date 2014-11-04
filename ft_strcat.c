/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:23:12 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 18:23:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *s1, const char *s2)
{
	char			*str;
	size_t			i;

	str = s1;
	while (*str != '\0')
		str++;
	i = 0;
	while (s2[i] != '\0')
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (s1);
}
