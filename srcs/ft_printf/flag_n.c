/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:52:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <sys/types.h>
#include <inttypes.h>
#include <stddef.h>

void			flag_n(t_string *out, t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "hh"))
		*(va_arg(*ap, signed char*)) = out->length;
	else if (ft_strequ(opt->length, "h"))
		*(va_arg(*ap, short*)) = out->length;
	else if (ft_strequ(opt->length, "ll"))
		*(va_arg(*ap, unsigned long long*)) = out->length;
	else if (ft_strequ(opt->length, "l"))
		*(va_arg(*ap, unsigned long*)) = out->length;
	else if (ft_strequ(opt->length, "j"))
		*(va_arg(*ap, uintmax_t*)) = out->length;
	else if (ft_strequ(opt->length, "t"))
		*(va_arg(*ap, ptrdiff_t*)) = out->length;
	else if (ft_strequ(opt->length, "z"))
		*(va_arg(*ap, long int*)) = out->length;
	else if (ft_strequ(opt->length, "q"))
		*(va_arg(*ap, u_quad_t*)) = out->length;
	else
		*(va_arg(*ap, unsigned int*)) = out->length;
}
