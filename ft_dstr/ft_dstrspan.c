/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrspan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 20:02:16 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:44:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"

char			*ft_dstrspan(t_dstr *str, int from, int to, int size)
{
	int				move;

	if (from < 0)
		from += str->length + 1;
	if (to < 0)
		to += str->length + 1;
	if (from > to)
	{
		move = from;
		from = to;
		to = move;
	}
	move = size - to + from;
	if (DSTR_NEED(str, move))
		ft_dstrextend(str, move);
	if (move != 0)
	{
		if ((str->length - to) > 0)
			ft_memmove(str->str + to + move, str->str + to, str->length - to);
		str->length += move;
		str->str[str->length] = '\0';
	}
	return (str->str + from);
}
