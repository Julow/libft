/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:27:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 17:47:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <wchar.h>

static int		push_wide(char *buff, int i, wchar_t w)
{
	char			tmp[4];
	int				len;

	len = ft_widetoa(tmp, w);
	i -= len;
	ft_memcpy(buff + i + 1, tmp, len);
	return (i);
}

void			flag_c(t_printf *pf, t_pfopt *opt)
{
	const int		len = MAX(opt->width, 1) * 4 + 1;
	int				i;
	char			c[len];

	i = len - 1;
	if (opt->format == 'C' || opt->length == pflen_l)
		i = push_wide(c, i, (wchar_t)va_arg(*(pf->ap), wint_t));
	else
		c[i--] = (char)va_arg(*(pf->ap), int);
	if (opt->flags & PFLAG_ZERO && !(opt->flags & PFLAG_MOINS))
		while ((len - i - 1) < opt->width)
			c[i--] = '0';
	margin_before(pf, opt, len - 1 - i);
	ft_write(pf->out, c + 1 + i, len - 1 - i);
	pf->printed += len - 1 - i;
	margin_after(pf, opt, len - 1 - i);
}
