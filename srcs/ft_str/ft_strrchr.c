/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:31:10 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 13:31:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	int				i;
	char			search;

	search = (char)c;
	i = ft_strlen(s) - 1;
	if (search == '\0')
		return (i + 1 + (char*)s);
	while (i >= 0)
	{
		if (s[i] == search)
			return (i + (char*)s);
		i--;
	}
	return (NULL);
}
