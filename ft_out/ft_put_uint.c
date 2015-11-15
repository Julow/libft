/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:24:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_put_uint(t_out *out, uint64_t val)
{
	uint32_t const	buff_size = MAX(WRITE_INT_BUFF, out->precision);
	char			buff[buff_size];
	uint32_t		i;

	i = buff_size - 1;
	while (val > 0)
	{
		buff[i--] = out->base.str[val % out->base.length];
		val /= out->base.length;
	}
	if (out->flags & (OUT_PLUS | OUT_SPACE))
	{
		buff[i--] = (out->flags & OUT_PLUS) ? '+' : ' ';
		out->flags &= ~(OUT_SPACE | OUT_PLUS);
	}
	out_before(out, buff_size - i);
	out_writestr(out, buff + i + 1, buff_size - i - 1);
	out_after(out, buff_size - i);
}
