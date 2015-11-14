/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/13 22:13:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_write_int(t_out *out, int64_t val)
{
	int32_t const	sign = (val < 0) ? -1 : 1;
	uint32_t		buff_size = MAX(WRITE_INT_BUFF, out->precision);
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
	else if (out->flags & OUT_PLUS)
	{
		buff[i--] = '+';
		out->flags &= ~(OUT_SPACE | OUT_PLUS);
	}
	else if (out->flags & OUT_SPACE)
	{
		buff[i--] = ' ';
		out->flags &= ~(OUT_SPACE | OUT_PLUS);
	}
	ft_write_sub(out, SUB(buff + i, buff_size - i));
}
