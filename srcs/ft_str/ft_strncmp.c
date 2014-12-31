/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:07:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 12:07:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, t_uint n)
{
	t_uint			i;
	t_uchar			*str1;
	t_uchar			*str2;

	str1 = (t_uchar*)s1;
	str2 = (t_uchar*)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == '\0')
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
