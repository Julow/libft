/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:16:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 19:16:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strichri(const char *str, char c)
{
	char			*tmp;

	tmp = (char*)str;
	c = LOWER(c);
	while (LOWER(*tmp) != c)
	{
		if (*tmp == '\0')
			return (-1);
		tmp++;
	}
	return (tmp - str);
}
