/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:01:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/06 17:32:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			append_out_flush(t_append_out *out)
{
	out->dst->length += out->out.buff_i;
	ft_dstrextend(out->dst, 1);
	out->dst->str[out->dst->length] = '\0';
	out->out.buff = out->dst->str + out->dst->length;
	out->out.buff_i = 0;
	out->out.buff_size = out->dst->capacity - out->dst->length;
}

t_dstr			ft_aprintf(char const *format, ...)
{
	va_list			ap;
	t_dstr			dst;
	t_append_out	out;

	dst = DSTR0();
	out = APPEND_OUT(&dst);
	va_start(ap, format);
	ft_putf(V(&out), format, &ap);
	va_end(ap);
	ft_flush(V(&out));
	return (dst);
}

void			ft_asprintf(t_dstr *str, char const *format, ...)
{
	va_list			ap;
	t_append_out	out;

	out = APPEND_OUT(str);
	out.out.buff_i = str->length;
	va_start(ap, format);
	ft_putf(V(&out), format, &ap);
	va_end(ap);
	ft_flush(V(&out));
}
