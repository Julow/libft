/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 14:27:41 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 15:36:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			format_d(t_out *out, t_f_info *info, va_list *ap)
{
	int64_t			val;

	if (info->format == 'D' && info->length == f_length_def)
		val = (int64_t)va_arg(*ap, long int);
	else
		val = get_signed_arg(ap, info->length);
	ft_write_int(out, val);
}

void			format_x(t_out *out, t_f_info *info, va_list *ap)
{
	uint64_t		val;

	if (info->format == 'X')
		out->base = SUBC(BASE_16);
	else
		out->base = SUBC(BASE_16_LOWER);
	val = get_unsigned_arg(ap, info->length);
	ft_write_uint(out, val);
}

void			format_o(t_out *out, t_f_info *info, va_list *ap)
{
	uint64_t		val;

	if (info->format == 'O' && info->length == f_length_def)
		val = (uint64_t)va_arg(*ap, unsigned long int);
	else
		val = get_unsigned_arg(ap, info->length);
	out->base = SUBC(BASE_8);
	ft_write_uint(out, val);
}

void			format_b(t_out *out, t_f_info *info, va_list *ap)
{
	uint64_t		val;

	val = get_unsigned_arg(ap, info->length);
	out->base = SUBC(BASE_2);
	ft_write_uint(out, val);
}

void			format_u(t_out *out, t_f_info *info, va_list *ap)
{
	uint64_t		val;

	if (info->format == 'U' && info->length == f_length_def)
		val = (uint64_t)va_arg(*ap, unsigned long int);
	else
		val = get_unsigned_arg(ap, info->length);
	ft_write_uint(out, val);
}
