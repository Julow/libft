/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:26:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:35:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_uint	ft_strlen(const char *str)
{
	char			*tmp;

	if (str == NULL)
		return (0);
	tmp = (char*)str;
	while (*tmp != '\0')
		tmp++;
	return (tmp - str);
}
