/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:52:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 17:14:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <sys/types.h>
#include <inttypes.h>
#include <stddef.h>

void			flag_n(t_printf *pf, t_pfopt *opt)
{
	if (opt->length == pflen_hh)
		*(va_arg(*(pf->ap), signed char*)) = pf->printed;
	else if (opt->length == pflen_h)
		*(va_arg(*(pf->ap), short*)) = pf->printed;
	else if (opt->length == pflen_ll)
		*(va_arg(*(pf->ap), unsigned long long*)) = pf->printed;
	else if (opt->length == pflen_l)
		*(va_arg(*(pf->ap), unsigned long*)) = pf->printed;
	else if (opt->length == pflen_j)
		*(va_arg(*(pf->ap), uintmax_t*)) = pf->printed;
	else if (opt->length == pflen_t)
		*(va_arg(*(pf->ap), ptrdiff_t*)) = pf->printed;
	else if (opt->length == pflen_z)
		*(va_arg(*(pf->ap), long int*)) = pf->printed;
	else if (opt->length == pflen_q)
		*(va_arg(*(pf->ap), u_quad_t*)) = pf->printed;
	else
		*(va_arg(*(pf->ap), unsigned int*)) = pf->printed;
}
