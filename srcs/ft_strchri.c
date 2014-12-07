/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/ft_strchri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 15:26:33 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/07 15:26:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strchri(char *str, char c)
{
	char			*tmp;

	tmp = str;
	while (*tmp != c)
	{
		if (*tmp == '\0')
			return (-1);
		tmp++;
	}
	return (tmp - str);
}
