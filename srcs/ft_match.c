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
	while (TRUE)
	{
		while (*str == '\0' && *pattern == '*')
			pattern++;
		if (*str == '\0' || *pattern == '\0')
			return ((*str == *pattern) ? TRUE : FALSE);
		if (*pattern == '*' && ft_match(str + 1, pattern))
			return (TRUE);
		while (*pattern == '*')
			pattern++;
		if (*str != *pattern)
			return (FALSE);
		while (*str == *pattern && *str != '\0' && *pattern != '*')
		{
			str++;
			pattern++;
		}
	}
}
