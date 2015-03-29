/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:12:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/29 03:04:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

const char		*rmatch(const char *str, const char *pattern)
{
	while (true)
	{
		if (*pattern == REG_START)
			return (reg_match(str, pattern));
		if (*pattern == '\0')
			break ;
		if (*str != *pattern)
			return (NULL);
		str++;
		pattern++;
	}
	return (str);
}

t_bool			ft_rmatch(const char *str, const char *pattern)
{
	const char		*tmp = rmatch(str, pattern);

	if (tmp != NULL && *tmp == '\0')
		return (true);
	return (false);
}
