/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:35:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:48:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_strequ(const char *s1, const char *s2)
{
	t_uint			i;

	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? true : false);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((s1[i] == s2[i]) ? true : false);
}
