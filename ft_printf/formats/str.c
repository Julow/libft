/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 15:22:25 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:26:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include "ft_wchar.h"
#include <wchar.h>

/*
** TODO: improve
*/
static void		format_ws(t_out *out, wchar_t const *wstr)
{
	int const		wlen = ft_wstrlen(wstr) * 4;
	char			str[wlen];
	int				length;

	length = ft_wstrnconv(str, wstr,
		(out->precision == 0) ? wlen : out->precision);
	ft_put_str(out, str, length);
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
	ft_put_sub(out, sub);
}
