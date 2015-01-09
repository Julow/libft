/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:34:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:33:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

t_string		*ft_stringf(const char *format, ...)
{
	t_string		*str;
	va_list			ap;

	str = ft_stringnew();
	va_start(ap, format);
	parsef(str, (char*)format, &ap);
	va_end(ap);
	return (str);
}

int				ft_printf(const char *format, ...)
{
	t_string		output;
	va_list			ap;

	ft_stringini(&output);
	va_start(ap, format);
	parsef(&output, (char*)format, &ap);
	ft_stringput(&output);
	va_end(ap);
	free(output.content);
	return (output.length);
}

int				ft_fdprintf(const int fd, const char *format, ...)
{
	t_string		output;
	va_list			ap;

	ft_stringini(&output);
	va_start(ap, format);
	parsef(&output, (char*)format, &ap);
	ft_stringputfd(&output, fd);
	va_end(ap);
	free(output.content);
	return (output.length);
}
