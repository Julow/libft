/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:41:08 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:47:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			ft_printf(char const *format, ...)
{
	va_list			ap;

	va_start(ap, format);
	ft_putf(FTOUT, format, &ap);
	va_end(ap);
}

void			ft_dprintf(int fd, char const *format, ...)
{
	int const		old_fd = g_ftout.fd;
	va_list			ap;

	va_start(ap, format);
	ft_out(fd);
	ft_putf(FTOUT, format, &ap);
	ft_out(old_fd);
	va_end(ap);
}

void			ft_fprintf(t_out *out, char const *format, ...)
{
	va_list			ap;

	va_start(ap, format);
	ft_putf(out, format, &ap);
	va_end(ap);
}

void			ft_sprintf(char *buff, char const *format, ...);

void			ft_snprintf(char *buff, uint32_t len, char const *format, ...);
