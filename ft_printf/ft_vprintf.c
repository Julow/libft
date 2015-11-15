/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:41:08 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 16:33:00 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void	ft_vprintf(char const *format, va_list ap)
{
	va_list		ap_cpy;

	va_copy(ap_cpy, ap);
	ft_write_f(FTOUT, format, &ap_cpy);
	va_end(ap_cpy);
}

void	ft_vdprintf(int fd, char const *format, va_list ap)
{
	int const	old_fd = g_ftout.fd;
	va_list		ap_cpy;

	ft_out(fd);
	va_copy(ap_cpy, ap);
	ft_write_f(FTOUT, format, &ap_cpy);
	va_end(ap_cpy);
	ft_out(old_fd);
}

void	ft_vfprintf(t_out *out, char const *format, va_list ap)
{
	va_list		ap_cpy;

	va_copy(ap_cpy, ap);
	ft_write_f(out, format, &ap_cpy);
	va_end(ap_cpy);
}

void	ft_vsprintf(char *buff, char const *format, va_list ap);

void	ft_vsnprintf(char *buff, uint32_t len, char const *format, va_list ap);
