/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isato.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:52:32 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/29 17:52:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_isato(const char *str)
{
	while (ft_iswhite(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	return (*str >= '0' && *str <= '9') ? TRUE : FALSE;
}
