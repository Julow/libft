/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 22:30:26 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 22:40:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strout.h"
#include <stdlib.h>

#define STROUT_MIN_BUFF		32

t_sub			ft_strout_sub(t_strout const *out)
{
	return (SUB(out->buff, out->buff_i));
}

void			ft_strout_clear(t_strout *out)
{
	if (out->buff_size > 0)
	{
		free(out->buff);
		out->buff = "";
		out->buff_i = 0;
		out->buff_size = 0;
	}
}

void			ft_strout_flush(t_strout *out)
{
	char *const		tmp = out->buff;
	uint32_t		new_size;

	if (out->buff_i < out->buff_size)
		return ;
	new_size = MAX(out->buff_size * 2, STROUT_MIN_BUFF);
	out->buff = MAL(char, new_size);
	if (out->buff_i > 0)
		ft_memcpy(out->buff, tmp, out->buff_i);
	if (out->buff_size > 0)
		free(tmp);
	out->buff_size = new_size;
}
