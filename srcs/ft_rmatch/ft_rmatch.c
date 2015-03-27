/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:12:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 15:32:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

t_bool			ft_rmatch(const char *str, const char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (true);
	if (*pattern == REG_START)
		return (reg_match(str, pattern));
	return ((*str == *pattern) ? ft_rmatch(str + 1, pattern + 1) : 0);
}
