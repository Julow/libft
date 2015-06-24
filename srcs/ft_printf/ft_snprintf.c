/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 22:45:32 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 23:53:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

int				ft_snprintf(char *dst, int max_len, const char *format, ...)
{
	t_printf		pf;
	va_list			ap;
	t_out			out;

	va_start(ap, format);
	out = BUFF_OUT(dst, max_len);
	pf = (t_printf){&out, 0, &ap};
	writef(&pf, format);
	ft_writechar(&out, '\0');
	va_end(ap);
	return (pf.printed);
}
