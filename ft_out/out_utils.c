/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:20:26 by juloo             #+#    #+#             */
/*   Updated: 2015/11/14 21:16:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			out_writestr(t_out *out, char const *str, uint32_t len)
{
	uint32_t		i;
	uint32_t		tmp;

	i = 0;
	while (true)
	{
		tmp = MIN(len - i, out->buff_size - out->buff_i);
		ft_memcpy(out->buff + out->buff_i, str + i, tmp);
		if (SHOULD_TRANSFORM(out->flags))
			out_transform(out->flags, out->buff + out->buff_i, tmp);
		out->buff_i += tmp;
		i += tmp;
		if (i >= len)
			break ;
		out->flush(out);
	}
}

void			out_writenchar(t_out *out, char c, uint32_t n)
{
	uint32_t		tmp;

	while (true)
	{
		tmp = MIN(n, out->buff_size - out->buff_i);
		ft_memset(out->buff + out->buff_i, c, tmp);
		out->buff_i += tmp;
		n -= tmp;
		if (n == 0)
			break ;
		out->flush(out);
	}
}

void			ft_flush(t_out *out)
{
	out->flush(out);
}
