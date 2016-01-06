/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:15:46 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:14:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_buff.h"

bool			ft_parsestr(t_buff *buff, const char *str)
{
	while (*str != '\0')
	{
		if (!BIS(buff, *str))
			return (false);
		str++;
	}
	return (true);
}
