/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 00:28:50 by juloo             #+#    #+#             */
/*   Updated: 2015/05/26 01:34:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
t_sub			ft_sub(char *str, int from, int to)
{
	int				str_len;

	if (from < 0 || to < 0)
	{
		str_len = ft_strlen(str) + 1;
		if (from < 0)
			from += str_len;
		if (to < 0)
			to += str_len;
	}
	return ((t_sub){str + from, to - from});
}
