/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 15:05:07 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/15 15:05:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_nmatch(char *str, char *pattern)
{
	while (*str == '\0' && *pattern == '*')
		pattern++;
	if (*str == '\0' || *pattern == '\0')
		return ((*str == *pattern) ? 1 : 0);
	if (*pattern == '*')
		return (ft_nmatch(str, pattern + 1) + ft_nmatch(str + 1, pattern));
	return ((*str == *pattern) ? ft_nmatch(str + 1, pattern + 1) : 0);
}
