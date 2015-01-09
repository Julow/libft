/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:52:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 12:59:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			ft_debug(char *file, int line, const char *format, ...)
{
	va_list			ap;
	t_string		out;

	va_start(ap, format);
	ft_putstr_fd(file, 2);
	ft_putchar_fd(':', 2);
	ft_putnbr_fd(line, 2);
	ft_stringini(&out);
	parsef(&out, format, &ap);
	ft_stringputfd(&out, 2);
	ft_putchar_fd('\n', 2);
	free(out.content);
	va_end(ap);
}
