/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:25:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 15:13:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

int				ft_fdprintf(int fd, const char *format, ...)
{
	t_printf		pf;
	va_list			ap;
	int				old_fd;

	old_fd = FTOUT->fd;
	ft_out(fd);
	va_start(ap, format);
	pf = (t_printf){FTOUT, 0, &ap};
	writef(&pf, format);
	va_end(ap);
	ft_flush(pf.out);
	ft_out(old_fd);
	return (pf.printed);
}
