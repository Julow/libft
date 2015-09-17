/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:39:47 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 18:39:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	t_uint			i;
	t_uchar			*str1;
	t_uchar			*str2;

	str1 = (t_uchar*)s1;
	str2 = (t_uchar*)s2;
	i = 0;
	while (str1[i] != '\0' || str2[i] != str1[i])
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
