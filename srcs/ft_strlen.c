/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:26:28 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 11:26:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint			ft_strlen(const char *str)
{
	char			*tmp;

	if (str == NULL)
		return (0);
	tmp = (char*)str;
	while (*tmp != '\0')
		tmp++;
	return (tmp - str);
}
