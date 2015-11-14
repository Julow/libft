/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/13 18:11:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_write_uint(t_out *out, uint64_t val)
{
	uint32_t		buff_size = MAX(WRITE_INT_BUFF, out->precision);
	char			buff[buff_size];
	uint32_t		i;

	i = buff_size - 1;
	while (val > 0)
	{
		buff[i--] = out->base.str[val % out->base.length];
		val /= out->base.length;
	}
	if (out->flags & OUT_PLUS)
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
