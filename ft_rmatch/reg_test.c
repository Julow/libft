/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 17:10:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 15:04:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rmatch.h"
#include "rmatch_internal.h"

const char		*reg_test(const char *str, const char *pattern)
{
	while (true)
	{
		if (*pattern == REG_START)
			return (reg_match(str, &pattern));
		if (*pattern == '\0')
			break ;
		if (*str != *pattern)
			return (NULL);
		str++;
		pattern++;
	}
	return (str);
}
