/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 22:46:16 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 15:13:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include "ft_dstr.h"

int				ft_asprintf(t_dstr *dst, const char *format, ...)
{
	t_printf		pf;
	va_list			ap;
	t_out			out;

	va_start(ap, format);
	out = DSTR_OUT(dst);
	pf = (t_printf){&out, 0, &ap};
	writef(&pf, format);
	va_end(ap);
	return (pf.printed);
}
