/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:15:29 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/15 12:41:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

bool			ft_subnext(t_sub sub, t_sub *match, t_sub sep)
{
	uint32_t		start;
	uint32_t		tmp;

	start = match->str + match->length - sub.str;
	while (start < sub.length)
	{
		tmp = ft_subfind(sub, sep, start);
		if (start >= tmp)
		{
			start = tmp + sep.length;
			continue ;
		}
		*match = SUB(sub.str + start, tmp - start);
		return (true);
	}
	*match = SUB(sub.str + sub.length, 0);
	return (false);
}

bool			ft_subnext_c(t_sub sub, t_sub *match, char sep)
{
	uint32_t		start;
	uint32_t		tmp;

	start = match->str + match->length - sub.str;
	while (start < sub.length)
	{
		tmp = ft_subfind_c(sub, sep, start);
		if (start >= tmp)
		{
			start = tmp + 1;
			continue ;
		}
		*match = SUB(sub.str + start, tmp - start);
		return (true);
	}
	*match = SUB(sub.str + sub.length, 0);
	return (false);
}

bool			ft_subnext_is(t_sub sub, t_sub *match, uint32_t sep)
{
	uint32_t		start;
	uint32_t		tmp;

	start = match->str + match->length - sub.str;
	while (start < sub.length)
	{
		tmp = ft_subfind_is(sub, sep, start);
		if (start >= tmp)
		{
			start = tmp + 1;
			continue ;
		}
		*match = SUB(sub.str + start, tmp - start);
		return (true);
	}
	*match = SUB(sub.str + sub.length, 0);
	return (false);
}
