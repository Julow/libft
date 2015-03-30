/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 23:58:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 23:58:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

int				ft_writef(t_out *out, const char *format, ...)
{
	t_string		output;
	va_list			ap;

	ft_stringini(&output);
	va_start(ap, format);
	parsef(&output, (char*)format, &ap);
	ft_write(out, output.content, output.length);
	va_end(ap);
	free(output.content);
	return (output.length);
}
