/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrspan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 20:02:16 by juloo             #+#    #+#             */
/*   Updated: 2017/02/13 15:02:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"

char			*ft_dstrspan(t_dstr *str, uint32_t from, uint32_t to,
					char const *src, uint32_t size)
{
	int32_t			move;

	if (from > to)
		return (ft_dstrspan(str, to, from, src, size));
	move = (int)size - (int)to + from;
	if (move != 0)
	{
		if (move > 0 && DSTR_NEED(str, move))
			ft_dstrextend(str, move);
		if ((str->length - to) > 0)
			memmove(str->str + to + move, str->str + to, str->length - to);
		str->length += move;
		str->str[str->length] = '\0';
	}
	if (src != NULL)
		memcpy(str->str + from, src, size);
	return (str->str + from);
}
