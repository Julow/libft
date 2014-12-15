/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 15:04:25 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/15 15:04:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_match(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '*')
		return (ft_match(str, pattern + 1));
	if (*str == '\0' || *pattern == '\0')
		return ((*str == '\0' && *pattern == '\0') ? 1 : 0);
	if (*pattern == '*')
		return (ft_match(str, pattern + 1) | ft_match(str + 1, pattern));
	return ((*str == *pattern) ? ft_match(str + 1, pattern + 1) : 0);
}
