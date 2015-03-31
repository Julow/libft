/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 13:46:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 18:05:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			writef(t_printf *pf, const char *format)
{
	while (*format != '\0')
	{
		if (*format == '%')
			format += parse_format(pf, format + 1) + 1;
		else
		{
			pf->printed++;
			ft_writechar(pf->out, *format);
			format++;
		}
	}
}
