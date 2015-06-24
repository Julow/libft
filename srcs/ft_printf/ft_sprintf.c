/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 22:43:25 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 22:45:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

int				ft_sprintf(char *dst, const char *format, ...)
{
	t_printf		pf;
	va_list			ap;
	t_out			out;

	va_start(ap, format);
	out = BUFF_OUT(dst, (t_uint)-1);
	pf = (t_printf){&out, 0, &ap};
	writef(&pf, format);
	va_end(ap);
	return (pf.printed);
}
