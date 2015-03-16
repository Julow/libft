/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:15:46 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 00:23:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_parsestr(t_buff *buff, const char *str)
{
	while (*str != '\0')
	{
		if (!BIS(buff, *str))
			return (false);
		str++;
	}
	return (true);
}
