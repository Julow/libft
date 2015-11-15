/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:27:02 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:26:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include <stdio.h>
/*
** TODO: stop using ft_write
*/
void			ft_put_f(t_out *out, char const *format, va_list *ap)
{
	uint32_t		i;
	uint32_t		last;

	i = 0;
	last = 0;
	while (format[i] != '\0')
		if (format[i] == '%')
		{
			if (i > last)
				ft_put_str(out, format + last, i - last);
			i += exec_format(out, format + i + 1, ap) + 1;
			last = i;
		}
		else
			i++;
	if (i > last)
		ft_put_str(out, format + last, i - last);
}
