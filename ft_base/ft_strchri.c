/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 15:26:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/08 20:24:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strchri(const char *str, char c)
{
	char			*tmp;

	tmp = (char*)str;
	while (*tmp != c)
	{
		if (*tmp == '\0')
			return (-1);
		tmp++;
	}
	return (tmp - str);
}
