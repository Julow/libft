/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 00:28:50 by juloo             #+#    #+#             */
/*   Updated: 2016/01/11 23:04:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

/*
** ft_sub
** ----
** Create a t_sub struct
** ----
** Examples:
** 				offset		length
** [0 : 5]		0			5
** [0 : -1]		0			strlen
** [0 : -2]		0			strlen - 1
** [2 : -1]		2			strlen - 2
** [2 : 5]		2			3
** [-1 : -1]	strlen		0
** [-3 : -1]	strlen - 2	2
** ----
** Note: Arguments are not checked (offset and length can be out of range)
** Note: Arguments are swaped if from > to
** ----
** Return t_sub struct
** ----
*/

t_sub			ft_sub(char const *str, int from, int to)
{
	uint32_t		str_len;

	if (from < 0 || to < 0)
	{
		str_len = ft_strlen(str) + 1;
		if (from < 0)
			from += str_len;
		if (to < 0)
			to += str_len;
	}
	if (from > to)
		return ((t_sub){str + to, from - to});
	return ((t_sub){str + from, to - from});
}

t_sub			ft_subsub(t_sub sub, int from, int to)
{
	if (from < 0)
		from += sub.length + 1;
	if (to < 0)
		to += sub.length + 1;
	if (from > to)
		return ((t_sub){sub.str + to, from - to});
	return ((t_sub){sub.str + from, to - from});
}

bool			ft_subequ(t_sub a, t_sub b)
{
	return (BOOL_OF(SUB_EQU(a, b)));
}

/*
** TODO: try to opti
*/
bool			ft_subequi(t_sub a, t_sub b)
{
	uint32_t		i;

	if (a.length != b.length)
		return (false);
	i = 0;
	while (i < a.length)
	{
		if (LOWER(a.str[i]) != LOWER(b.str[i]))
			return (false);
		i++;
	}
	return (true);
}
