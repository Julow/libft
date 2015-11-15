/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 21:35:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_putuint(t_out *out, uint64_t val)
{
	uint32_t const	preci = (out->precision == 0) ? 1 : out->precision;
	char			buff[WRITE_INT_BUFF];
	uint32_t		i;

	i = WRITE_INT_BUFF - 1;
	while (val != 0)
	{
		buff[i--] = out->base.str[val % out->base.length];
		val /= out->base.length;
	}
	if (out->flags & (OUT_PLUS | OUT_SPACE))
	{
		buff[i--] = (out->flags & OUT_PLUS) ? '+' : ' ';
		out->flags &= ~(OUT_SPACE | OUT_PLUS);
	}
	ft_putpad_left(out, MAX(WRITE_INT_BUFF - i, preci));
	if (preci > (WRITE_INT_BUFF - i - 1))
		ft_write_nchar(out, out->base.str[0], preci - (WRITE_INT_BUFF - i - 1));
	ft_write(out, buff + i + 1, WRITE_INT_BUFF - i - 1);
	ft_putpad_right(out, MAX(WRITE_INT_BUFF - i, preci));
	out->base = SUBC(BASE_10);
}
