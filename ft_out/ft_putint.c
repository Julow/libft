/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 13:07:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_putint(t_out *out, int64_t val)
{
	int32_t const	sign = (val < 0) ? -1 : 1;
	uint32_t const	preci = (out->precision == 0) ? 1 : out->precision;
	char			buff[WRITE_INT_BUFF];
	uint32_t		i;

	i = WRITE_INT_BUFF - 1;
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
	i++;
	ft_putpad_left(out, MAX(WRITE_INT_BUFF - i, preci));
	if (preci > (WRITE_INT_BUFF - i))
		ft_write_nchar(out, out->base.str[0], preci - (WRITE_INT_BUFF - i));
	ft_write(out, buff + i, WRITE_INT_BUFF - i);
	ft_putpad_right(out, MAX(WRITE_INT_BUFF - i, preci));
	out->base = SUBC(BASE_10);
}
