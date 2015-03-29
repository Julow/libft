/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 17:16:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/29 17:29:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

/*
** ft_rfind
** ---
** Evaluate regex and check if a sub string of 'str' match 'pattern'
** Put the first result into 'dst'
** ---
** Return
**  true if a match was found
**  false otherwise
** ---
*/
t_bool			ft_rfind(t_sub *dst, const char *str, const char *pattern)
{
	char const		*tmp;

	while (*str != '\0')
	{
		tmp = reg_test(str, pattern);
		if (tmp != NULL)
		{
			dst->str = (char*)str;
			dst->length = tmp - str;
			return (true);
		}
		str++;
	}
	dst->str = (char*)str;
	dst->length = 0;
	return (false);
}
