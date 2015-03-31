/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 13:42:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 16:42:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

int				ft_printf(const char *format, ...)
{
	t_printf		pf;
	va_list			ap;

	va_start(ap, format);
	pf = (t_printf){FTOUT, 0, &ap};
	writef(&pf, format);
	va_end(ap);
	ft_flush(pf.out);
	return (pf.printed);
}
