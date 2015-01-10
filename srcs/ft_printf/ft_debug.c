/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:52:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 18:23:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			ft_debug(const char *c, char *f, int l, const char *s, ...)
{
	va_list			ap;
	t_string		out;

	ft_fdprintf(2, "%s %s():%-3d ", f, c, l);
	if (s != NULL)
	{
		ft_stringini(&out);
		va_start(ap, s);
		parsef(&out, s, &ap);
		va_end(ap);
		ft_stringputfd(&out, 2);
		free(out.content);
	}
	ft_putchar_fd('\n', 2);
}
