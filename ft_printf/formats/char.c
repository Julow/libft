/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 15:44:26 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include "ft/ft_wchar.h"

static void		format_wc(t_out *out, wchar_t c)
{
	char			buff[4];
	int				length;

	length = ft_widetoa(buff, c);
	ft_putpad_left(out, 1);
	ft_write(out, buff, length);
	ft_putpad_right(out, 1);
}

void			format_c(t_out *out, t_f_info *info, va_list *ap)
{
	char			c;

	if (info->format == 'C' || info->length == f_length_ll
		|| info->length == f_length_l)
	{
		format_wc(out, va_arg(*ap, wchar_t));
		return ;
	}
	c = (char)va_arg(*ap, int);
	if (out->precision > 1)
		ft_putnchar(out, c, out->precision);
	else
		ft_putchar(out, c);
}

void			format_default(t_out *out, t_f_info *info, va_list *ap)
{
	if (info->format == '\0')
		return ;
	if (out->precision > 1)
		ft_putnchar(out, info->format, out->precision);
	else
		ft_putchar(out, info->format);
	(void)ap;
}
