/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 09:19:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:34:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			parsef(t_string *out, const char *format, va_list *ap)
{
	int				i;

	ft_stringext(out, ft_strlen(format));
	i = -1;
	while (++i >= 0)
	{
		if (format[i] == '%' || format[i] == '{' || format[i] == '\0')
		{
			if (format[i] == '\0')
				break ;
			else if (format[i] == '%')
				i += parse_format(out, format + i + 1, ap);
			else if (format[i] == '{')
				i += parse_meta(out, format + i + 1);
		}
		else
			ft_stringaddc(out, format[i]);
	}
}
