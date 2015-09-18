/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 12:51:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/18 15:46:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strcase
** =============
** Compare 's1' and 's2' case insensitive
*/
t_bool			ft_strcase(const char *s1, const char *s2)
{
	t_uint			i;

	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? true : false);
	i = 0;
	while (LOWER(s1[i]) == LOWER(s2[i]) && s1[i] != '\0')
		i++;
	return ((LOWER(s1[i]) == LOWER(s2[i])) ? true : false);
}
