/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:46:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_putint(t_out *out, int64_t val)
{
	int32_t const	sign = (val < 0) ? -1 : 1;
	uint32_t const	buff_size = MAX(WRITE_INT_BUFF, out->precision);
	char			buff[buff_size];
	uint32_t		i;

	i = buff_size - 1;
	while (val != 0)
	{
		buff[i--] = out->base.str[val % out->base.length * sign];
		val /= out->base.length;
	}
	if (sign < 0)
		buff[i--] = '-';
	else if (out->flags & (OUT_PLUS | OUT_SPACE))
	{
		buff[i--] = (out->flags & OUT_PLUS) ? '+' : ' ';
		out->flags &= ~(OUT_SPACE | OUT_PLUS);
	}
	ft_putpad_left(out, buff_size - i);
	ft_write(out, buff + i + 1, buff_size - i - 1);
	ft_putpad_right(out, buff_size - i);
}
