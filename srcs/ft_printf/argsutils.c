/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:27:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <sys/types.h>
#include <inttypes.h>
#include <stddef.h>

t_long			get_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "hh"))
		return ((t_long)(signed char)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "h"))
		return ((t_long)(short)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "ll"))
		return ((t_long)(va_arg(*ap, long long)));
	if (ft_strequ(opt->length, "l"))
		return ((t_long)(va_arg(*ap, long)));
	if (ft_strequ(opt->length, "j"))
		return ((t_long)(va_arg(*ap, intmax_t)));
	if (ft_strequ(opt->length, "t") || ft_strequ(opt->length, "I"))
		return ((t_long)(va_arg(*ap, ptrdiff_t)));
	if (ft_strequ(opt->length, "z"))
		return ((t_long)(va_arg(*ap, long)));
	if (ft_strequ(opt->length, "q") || ft_strequ(opt->length, "I64"))
		return ((t_long)(va_arg(*ap, quad_t)));
	return ((t_long)(va_arg(*ap, int)));
}

t_ulong			get_unsigned_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "hh"))
		return ((t_ulong)(unsigned char)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "h"))
		return ((t_ulong)(unsigned short)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "ll"))
		return ((t_ulong)(va_arg(*ap, unsigned long long)));
	if (ft_strequ(opt->length, "l"))
		return ((t_ulong)(va_arg(*ap, unsigned long)));
	if (ft_strequ(opt->length, "j"))
		return ((t_ulong)(va_arg(*ap, uintmax_t)));
	if (ft_strequ(opt->length, "t"))
		return ((t_ulong)(va_arg(*ap, ptrdiff_t)));
	if (ft_strequ(opt->length, "z") || ft_strequ(opt->length, "I"))
		return ((t_ulong)(va_arg(*ap, size_t)));
	if (ft_strequ(opt->length, "q") || ft_strequ(opt->length, "I64"))
		return ((t_ulong)(va_arg(*ap, u_quad_t)));
	return ((t_ulong)(va_arg(*ap, unsigned int)));
}

long double		get_float_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "L"))
		return (va_arg(*ap, long double));
	if (ft_strequ(opt->length, "l"))
		return ((long double)(va_arg(*ap, double)));
	return ((long double)(va_arg(*ap, double)));
}
