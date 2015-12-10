/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 22:49:00 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:22:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include "ft/ft_str_out.h"

static int	put_subformat(t_out *out, char const *fmt, char end, va_list *ap)
{
	int32_t			i;
	int32_t			last;

	i = 0;
	last = 0;
	while (fmt[i] != '\0' && fmt[i] != end)
		if (fmt[i] == '\\' && fmt[i + 1] == end)
		{
			if (i > last)
				ft_putstr(out, fmt + last, i - last);
			last = ++i;
			i++;
		}
		else if (fmt[i] == '%')
		{
			if (i > last)
				ft_putstr(out, fmt + last, i - last);
			i += exec_format(out, fmt + i + 1, ap) + 1;
			last = i;
		}
		else
			i++;
	if (i > last)
		ft_putstr(out, fmt + last, i - last);
	return (i + 1);
}

int			exec_subformat(t_out *out, char const *fmt, char end, va_list *ap)
{
	uint32_t const	repeat = (out->precision > 0) ? out->precision : 1;
	uint32_t		i;
	t_str_out		str_out;
	int				len;

	str_out = STR_OUT();
	out->precision = 0;
	len = put_subformat(V(&str_out), fmt, end, ap);
	ft_putpad_left(out, str_out.buff_i * repeat);
	i = 0;
	while (i < repeat)
	{
		ft_write(out, str_out.buff, str_out.buff_i);
		i++;
	}
	ft_putpad_right(out, str_out.buff_i * repeat);
	ft_str_out_clear(&str_out);
	return (len);
}
