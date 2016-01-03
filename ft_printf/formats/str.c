/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 15:22:25 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 14:06:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_wchar.h"
#include "printf_internal.h"

#include <wchar.h>

static void		format_ws(t_out *out, wchar_t const *wstr)
{
	int const		wlen = ft_wstrlen(wstr);
	char			str[wlen * 4];
	int				length;

	length = ft_wstrnconv(str, wstr,
		(out->precision == 0) ? wlen * 4 : out->precision);
	ft_putpad_left(out, wlen);
	ft_write(out, str, length);
	ft_putpad_right(out, wlen);
}

static t_sub	get_string_arg(t_out *out, t_f_length length, va_list *ap)
{
	t_sub			tmp;

	if (length == f_length_t)
		return (va_arg(*ap, t_sub));
	if (length == f_length_z)
		return (*(va_arg(*ap, t_sub const*)));
	tmp.str = va_arg(*ap, char const*);
	tmp.length = 0;
	if (tmp.str == NULL)
		return (tmp);
	if (out->precision == 0)
		tmp.length = ft_strlen(tmp.str);
	else
		while (tmp.length < out->precision && tmp.str[tmp.length] != '\0')
			tmp.length++;
	return (tmp);
}

void			format_s(t_out *out, t_f_info *info, va_list *ap)
{
	t_sub			sub;

	if (info->format == 'S' || info->length == f_length_ll
		|| info->length == f_length_l)
	{
		format_ws(out, va_arg(*ap, wchar_t const*));
		return ;
	}
	sub = get_string_arg(out, info->length, ap);
	if (sub.str == NULL)
		sub = SUBC("(null)");
	ft_putsub(out, sub);
}
