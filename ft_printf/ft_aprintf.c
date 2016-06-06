/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:01:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 17:14:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			append_out_flush(t_append_out *out)
{
	ft_dstrextend(out->dstr, 1);
	out->out.buff = out->dstr->str;
	out->dstr->str[out->dstr->length] = '\0';
}

t_dstr			ft_aprintf(char const *format, ...)
{
	va_list			ap;
	t_dstr			dst;
	t_append_out	out;

	dst = DSTR0();
	out = APPEND_OUT(&dst);
	va_start(ap, format);
	ft_putf(&out, format &ap);
	va_end(ap);
	ft_flush(&out);
	return (dst);
}

void			ft_asprintf(t_dstr *str, char const *format, ...)
{
	va_list			ap;
	t_append_out	out;

	out = APPEND_OUT(str);
	va_start(ap, format);
	ft_putf(&out, format &ap);
	va_end(ap);
	ft_flush(&out);
}
