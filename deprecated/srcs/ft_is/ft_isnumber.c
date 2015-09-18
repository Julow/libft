/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:53:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:49:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_isnumber(const char *str)
{
	while (ft_iswhite(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '.' || *str == ',')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	while (ft_iswhite(*str))
		str++;
	return (*str == '\0') ? true : false;
}
