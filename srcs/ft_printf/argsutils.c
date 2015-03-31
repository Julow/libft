/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:27:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 16:42:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <sys/types.h>
#include <inttypes.h>
#include <stddef.h>

t_long			get_arg(t_printf *pf, t_pfopt *opt)
{
	if (opt->length == pflen_hh)
		return ((t_long)(signed char)(va_arg(*(pf->ap), int)));
	if (opt->length == pflen_h)
		return ((t_long)(short)(va_arg(*(pf->ap), int)));
	if (opt->length == pflen_ll)
		return ((t_long)(va_arg(*(pf->ap), long long)));
	if (opt->length == pflen_l)
		return ((t_long)(va_arg(*(pf->ap), long)));
	if (opt->length == pflen_j)
		return ((t_long)(va_arg(*(pf->ap), intmax_t)));
	if (opt->length == pflen_t)
		return ((t_long)(va_arg(*(pf->ap), ptrdiff_t)));
	if (opt->length == pflen_z)
		return ((t_long)(va_arg(*(pf->ap), long)));
	if (opt->length == pflen_q)
		return ((t_long)(va_arg(*(pf->ap), quad_t)));
	return ((t_long)(va_arg(*(pf->ap), int)));
}

t_ulong			get_unsigned_arg(t_printf *pf, t_pfopt *opt)
{
	if (opt->length == pflen_hh)
		return ((t_ulong)(unsigned char)(va_arg(*(pf->ap), int)));
	if (opt->length == pflen_h)
		return ((t_ulong)(unsigned short)(va_arg(*(pf->ap), int)));
	if (opt->length == pflen_ll)
		return ((t_ulong)(va_arg(*(pf->ap), unsigned long long)));
	if (opt->length == pflen_l)
		return ((t_ulong)(va_arg(*(pf->ap), unsigned long)));
	if (opt->length == pflen_j)
		return ((t_ulong)(va_arg(*(pf->ap), uintmax_t)));
	if (opt->length == pflen_t)
		return ((t_ulong)(va_arg(*(pf->ap), ptrdiff_t)));
	if (opt->length == pflen_z)
		return ((t_ulong)(va_arg(*(pf->ap), size_t)));
	if (opt->length == pflen_q)
		return ((t_ulong)(va_arg(*(pf->ap), u_quad_t)));
	return ((t_ulong)(va_arg(*(pf->ap), unsigned int)));
}

long double		get_float_arg(t_printf *pf, t_pfopt *opt)
{
	if (opt->length == pflen_L)
		return (va_arg(*(pf->ap), long double));
	if (opt->length == pflen_l)
		return ((long double)(va_arg(*(pf->ap), double)));
	return ((long double)(va_arg(*(pf->ap), double)));
}
