/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_formats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 21:15:55 by juloo             #+#    #+#             */
/*   Updated: 2015/11/14 21:16:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			out_before(t_out *out, int32_t len)
{
	if (out->width < 0 && (len += out->width) < 0)
		out_writenchar(out, out->fill, -len);
	else if ((out->flags & OUT_CENTER)
		&& out->width > 0 && (len = out->width - len + 1) > 0)
		out_writenchar(out, out->fill, len / 2);
}

void			out_after(t_out *out, int32_t len)
{
	if (out->width > 0 && (len = out->width - len) > 0)
	{
		if (out->flags & OUT_CENTER)
			len /= 2;
		out_writenchar(out, out->fill, len);
	}
	out->fill = OUT_DEFAULT_FILL;
	out->width = 0;
	out->flags &= ~(OUT_TOLOWER | OUT_TOUPPER | OUT_CENTER);
}

void			out_transform(int flags, char *str, uint32_t len)
{
	char *const		end = str + len;

	while (str < end)
	{
		if (flags & OUT_TOUPPER && *str >= 'a' && *str <= 'z')
			*str -= 'a' - 'A';
		else if (flags & OUT_TOLOWER && *str >= 'A' && *str <= 'Z')
			*str += 'a' - 'A';
		str++;
	}
}
