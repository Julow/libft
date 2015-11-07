/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:26:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 15:13:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include <stdlib.h>

int				ft_writef(t_out *out, const char *format, ...)
{
	t_printf		pf;
	va_list			ap;

	va_start(ap, format);
	pf = (t_printf){out, 0, &ap};
	writef(&pf, format);
	va_end(ap);
	return (pf.printed);
}
