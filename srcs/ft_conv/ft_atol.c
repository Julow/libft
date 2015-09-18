/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 23:56:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/18 15:01:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_long			ft_atol(const char *str)
{
	t_long			nb;
	t_bool			negatif;

	negatif = false;
	nb = 0;
	while (IS(*str, IS_WHITE))
		str++;
	if (*str == '-')
	{
		negatif = true;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + (*(str++) - '0');
	return ((negatif) ? -nb : nb);
}
