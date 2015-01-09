/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:52:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:59:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			ft_debug(char *file, int line, const char *format, ...)
{
	va_list			ap;
	t_string		out;

	va_start(ap);
	ft_putstr(file, 2);
	ft_putchar(':', 2);
	ft_putnbr(line, 2);
	ft_stringini(out);
	parsef(&out, format, &ap);
	ft_stringput_fd(out, 2);
	ft_putchar_fd('\n', 2);
	free(out.content);
	va_end(ap);
}
