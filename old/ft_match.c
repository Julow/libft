/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 15:04:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:47:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_match(char *str, char *pattern)
{
	while (true)
	{
		while (*str == '\0' && *pattern == '*')
			pattern++;
		if (*str == '\0' || *pattern == '\0')
			return ((*str == *pattern) ? true : false);
		if (*pattern == '*' && ft_match(str + 1, pattern))
			return (true);
		while (*pattern == '*')
			pattern++;
		if (*str != *pattern)
			return (false);
		while (*str == *pattern && *str != '\0' && *pattern != '*')
		{
			str++;
			pattern++;
		}
	}
}
