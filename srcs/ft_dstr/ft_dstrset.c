/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:15:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 14:06:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

void			ft_dstrset(t_dstr *str, int from, int to, t_sub sub)
{
	int				move;

	if (from < 0)
		from += str->length + 1;
	if (to < 0)
		to += str->length + 1;
	move = sub.length - to + from;
	if (DSTR_NEED(str, move))
		ft_dstrextend(str, move);
	if (move != 0)
	{
		ft_memmove(str->str + to + move, str->str + to, str->length - to);
		str->length += move;
		str->str[str->length] = '\0';
	}
	ft_memcpy(str->str + from, sub.str, sub.length);
}
