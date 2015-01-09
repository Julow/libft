/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 12:51:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 12:52:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strncase
** =============
** Compare 's1' and 's2' case insensitive
** Compare 'n' characters
*/
t_bool			ft_strncase(const char *s1, const char *s2, t_uint n)
{
	t_uint			i;

	if (n == 0)
		return (TRUE);
	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? TRUE : FALSE);
	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] != '\0' && i < n)
		i++;
	return ((ft_tolower(s1[i]) == ft_tolower(s2[i])) ? TRUE : FALSE);
}
