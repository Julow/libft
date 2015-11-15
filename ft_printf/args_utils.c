/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:27:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/15 16:20:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include <sys/types.h>
#include <inttypes.h>
#include <stddef.h>

int64_t			get_signed_arg(va_list *ap, t_f_length length)
{
	if (length != f_length_def)
	{
		if (length == f_length_hh)
			return ((int64_t)(signed char)(va_arg(*ap, int)));
		if (length == f_length_h)
			return ((int64_t)(short)(va_arg(*ap, int)));
		if (length == f_length_ll)
			return ((int64_t)(va_arg(*ap, long long)));
		if (length == f_length_l)
			return ((int64_t)(va_arg(*ap, long)));
		if (length == f_length_j)
			return ((int64_t)(va_arg(*ap, intmax_t)));
		if (length == f_length_t)
			return ((int64_t)(va_arg(*ap, ptrdiff_t)));
		if (length == f_length_z)
			return ((int64_t)(va_arg(*ap, ssize_t)));
		if (length == f_length_q)
			return ((int64_t)(va_arg(*ap, int64_t)));
	}
	return ((int64_t)(va_arg(*ap, int)));
}

uint64_t		get_unsigned_arg(va_list *ap, t_f_length length)
{
	if (length != f_length_def)
	{
		if (length == f_length_hh)
			return ((uint64_t)(unsigned char)(va_arg(*ap, int)));
		if (length == f_length_h)
			return ((uint64_t)(unsigned short)(va_arg(*ap, int)));
		if (length == f_length_ll)
			return ((uint64_t)(va_arg(*ap, unsigned long long)));
		if (length == f_length_l)
			return ((uint64_t)(va_arg(*ap, unsigned long)));
		if (length == f_length_j)
			return ((uint64_t)(va_arg(*ap, uintmax_t)));
		if (length == f_length_t)
			return ((uint64_t)(va_arg(*ap, ptrdiff_t)));
		if (length == f_length_z)
			return ((uint64_t)(va_arg(*ap, size_t)));
		if (length == f_length_q)
			return ((uint64_t)(va_arg(*ap, u_int64_t)));
	}
	return ((uint64_t)(va_arg(*ap, unsigned int)));
}

double			get_float_arg(va_list *ap, t_f_length length)
{
	if (length == f_length_ll)
		return ((double)va_arg(*ap, long double));
	return (va_arg(*ap, double));
}
