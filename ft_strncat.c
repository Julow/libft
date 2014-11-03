/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:32:52 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 18:32:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*strncat(char *s1, const char *s2, size_t n)
{
	char			*str;
	size_t			i;

	str = s1;
	while (*str != '\0')
		str++;
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (s1);
}
