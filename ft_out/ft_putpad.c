/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 20:40:16 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:50:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_putpad_left(t_out *out, int32_t len)
{
	int32_t const	width = (out->flags & OUT_MINUS) ? -out->width : out->width;

	if (width < 0 && (len += width) < 0)
		ft_write_nchar(out, out->fill, -len);
	else if ((out->flags & OUT_CENTER) && width > 0
		&& (len = width - len + 1) > 0)
		ft_write_nchar(out, out->fill, len / 2);
}

void			ft_putpad_right(t_out *out, int32_t len)
{
	int32_t const	width = (out->flags & OUT_MINUS) ? -out->width : out->width;

	if (width > 0 && (len = width - len) > 0)
	{
		if (out->flags & OUT_CENTER)
			len /= 2;
		ft_write_nchar(out, out->fill, len);
	}
	out->fill = OUT_DEFAULT_FILL;
	out->width = 0;
	out->flags = 0;
}
