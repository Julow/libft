/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:20:26 by juloo             #+#    #+#             */
/*   Updated: 2015/11/13 22:01:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			out_writenchar(t_out *out, char c, uint32_t n)
{
	uint32_t		tmp;

	while (true)
	{
		tmp = MIN(n, out->buff_size - out->buff_i);
		ft_memset(out->buff + out->buff_i, c, tmp);
		out->buff_i += tmp;
		n -= tmp;
		if (n == 0)
			break ;
		out->flush(out);
	}
}

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

void			ft_flush(t_out *out)
{
	out->flush(out);
}
