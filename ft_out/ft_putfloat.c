/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:46:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

static uint32_t	left_part(t_out *out, char *buff, uint32_t i, double val)
{
	t_bool			neg;

	if (val < 0.0)
	{
		val = -val;
		neg = true;
	}
	else
		neg = false;
	buff[i--] = '.';
	while (val >= 1.0)
	{
		buff[i--] = out->base.str[((uint64_t)val) % out->base.length];
		val /= 10.0;
	}
	if (neg)
		buff[i--] = '-';
	else if (out->flags & (OUT_PLUS | OUT_SPACE))
	{
		buff[i--] = (out->flags & OUT_PLUS) ? '+' : ' ';
		out->flags &= ~(OUT_SPACE | OUT_PLUS);
	}
	return (i + 1);
}

void			ft_putfloat(t_out *out, double val)
{
	char			buff[WRITE_FLOAT_BUFF];
	uint32_t		precision;
	uint32_t		len;
	uint32_t		i;

	i = left_part(out, buff, WRITE_FLOAT_BUFF - 1, val);
	precision = (out->precision == 0) ? DEF_PRECI : out->precision;
	len = WRITE_FLOAT_BUFF - i + precision;
	ft_putpad_left(out, len);
	ft_write(out, buff + i, WRITE_FLOAT_BUFF - i);
	if (val < 0.0)
		val = -val;
	i = 0;
	while (precision-- > 0)
	{
		val *= 10.0;
		buff[i++] = out->base.str[((uint64_t)val) % out->base.length];
	}
	ft_write(out, buff, i);
	ft_putpad_right(out, len);
}
