/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matchint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:25:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/29 21:52:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MIN_INT_STR		"-2147483648"
#define MAX_INT_STR		"2147483647"

/*
** ft_matchint
** ---
** Test if 'str' start with a valid int
** ---
** Return
**  the len of the int
**  0 if 'str' don't start with a valid int
** ---
*/
int				ft_matchint(const char *str)
{
	int				len;

	len = (*str == '-') ? 1 : 0;
	while (ft_isdigit(str[len]))
		len++;
	if (len == 1 && *str == '-')
		return (0);
	if (*str == '-')
	{
		if (len == 11 && ft_memcmp(str, MIN_INT_STR, 11) > 0)
			return (0);
		if (len > 11)
			return (0);
	}
	else if (len == 10 && ft_memcmp(str, MAX_INT_STR, 10) > 0)
		return (0);
	else if (len > 10)
		return (0);
	return (len);
}
