/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 20:40:16 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 18:46:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_putpad_left(t_out *out, int32_t len)
{
	int32_t const	width = (out->flags & OUT_MINUS) ? -out->width : out->width;

	len -= out->prefix.length;
	if (out->flags & OUT_CENTER)
		len = (ABS(width) - len + ((width < 0) ? 2 : 1)) / 2;
	else if (width > 0)
		len = width - len;
	else
		len = 0;
	if (len > 0)
		ft_write_nchar(out, out->fill, len);
	if (out->prefix.length > 0)
	{
		ft_write(out, out->prefix.str, out->prefix.length);
		out->prefix = SUB0();
	}
}

void			ft_putpad_right(t_out *out, int32_t len)
{
	int32_t const	width = (out->flags & OUT_MINUS) ? -out->width : out->width;

	if (out->suffix.length > 0)
	{
		len -= out->suffix.length;
		ft_write(out, out->suffix.str, out->suffix.length);
		out->suffix = SUB0();
	}
	if (out->flags & OUT_CENTER)
		len = (ABS(width) - len + ((width > 0) ? 2 : 1)) / 2;
	else if (width < 0)
		len = -(len + width);
	else
		len = 0;
	if (len > 0)
		ft_write_nchar(out, out->fill, len);
	out->fill = OUT_DEFAULT_FILL;
	out->width = 0;
	out->flags = 0;
}
