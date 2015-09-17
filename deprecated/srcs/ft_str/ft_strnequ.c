/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:42:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:47:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_strnequ(const char *s1, const char *s2, t_uint n)
{
	t_uint			i;

	if (n == 0)
		return (true);
	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? true : false);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i >= n)
		i = n - 1;
	return ((s1[i] == s2[i]) ? true : false);
}
