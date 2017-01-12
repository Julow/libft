/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 22:30:26 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:15:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_str_out.h"
#include <stdlib.h>

#define STR_OUT_MIN_BUFF		32

t_sub			ft_str_out_sub(t_str_out const *out)
{
	return (SUB(out->buff, out->buff_i));
}

void			ft_str_out_clear(t_str_out *out)
{
	if (out->buff_size > 0)
	{
		free(out->buff);
		out->buff = "";
		out->buff_i = 0;
		out->buff_size = 0;
	}
}

void			ft_str_out_flush(t_str_out *out)
{
	char *const		tmp = out->buff;
	uint32_t		new_size;

	if (out->buff_i < out->buff_size)
		return ;
	new_size = MAX(out->buff_size * 2, STR_OUT_MIN_BUFF);
	out->buff = MALLOC(new_size);
	if (out->buff_i > 0)
		memcpy(out->buff, tmp, out->buff_i);
	if (out->buff_size > 0)
		free(tmp);
	out->buff_size = new_size;
}
