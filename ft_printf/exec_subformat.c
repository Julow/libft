/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 22:49:00 by juloo             #+#    #+#             */
/*   Updated: 2015/11/28 16:19:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include "ft/ft_count_out.h"

static int		put_subformat(t_out *out, char const *format, char end,
					va_list *ap, uint32_t extra_flags)
{
	int32_t			i;
	int32_t			last;

	i = 0;
	last = 0;
	while (format[i] != '\0')
		if (format[i] == end)
			break ;
		else if (format[i] == '%')
		{
			out->flags |= extra_flags;
			if (i > last)
				ft_putstr(out, format + last, i - last);
			out->flags |= extra_flags;
			i += exec_format(out, format + i + 1, ap) + 1;
			last = i;
		}
		else
			i++;
	out->flags |= extra_flags;
	if (i > last)
		ft_putstr(out, format + last, i - last);
	return (i + 1);
}

int				exec_subformat(t_out *out, char const *format, char end,
					va_list *ap)
{
	uint32_t const	out_flags = out->flags;
	uint32_t const	out_width = out->width;
	t_count_out		count_out;
	va_list			ap_cpy;
	int				len;

	count_out = COUNT_OUT();
	va_copy(ap_cpy, *ap);
	put_subformat(V(&count_out), format, end, &ap_cpy, 0);
	ft_flush(V(&count_out));
	va_end(ap_cpy);
	ft_putpad_left(out, count_out.count);
	out->flags = 0;
	out->width = 0;
	len = put_subformat(out, format, end, ap, out_flags & OUT_REVCASE);
	out->flags = out_flags;
	out->width = out_width;
	ft_putpad_right(out, count_out.count);
	return (len);
}
