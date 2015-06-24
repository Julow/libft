/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 22:47:00 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 22:51:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include "ft_dstr.h"

t_dstr			ft_aprintf(const char *format, ...)
{
	t_printf		pf;
	va_list			ap;
	t_out			out;
	t_dstr			dstr;

	va_start(ap, format);
	dstr = DSTR0();
	out = DSTR_OUT(&dstr);
	pf = (t_printf){&out, 0, &ap};
	writef(&pf, format);
	va_end(ap);
	return (dstr);
}
