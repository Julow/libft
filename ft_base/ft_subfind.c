/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:15:29 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/11 17:44:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

uint32_t		ft_subfind(t_sub sub, t_sub search, uint32_t start)
{
	uint32_t const	max = sub.length - search.length;
	uint32_t		i;

	i = start;
	if (sub.length >= search.length && search.length > 0)
		while (i <= max)
		{
			if (sub.str[i] == search.str[0]
				&& ft_memcmp(sub.str + i, search.str, search.length) == 0)
				return (i);
			i++;
		}
	return (sub.length);
}

uint32_t		ft_subfind_c(t_sub sub, char search, uint32_t start)
{
	uint32_t		i;

	i = start;
	while (i < sub.length)
	{
		if (sub.str[i] == search)
			return (i);
		i++;
	}
	return (sub.length);
}

uint32_t		ft_subfind_is(t_sub sub, t_is search, uint32_t start)
{
	uint32_t		i;

	i = start;
	while (i < sub.length)
	{
		if (IS(sub.str[i], search))
			return (i);
		i++;
	}
	return (sub.length);
}
