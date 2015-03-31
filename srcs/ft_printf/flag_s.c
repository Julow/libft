/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:11:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 18:41:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <wchar.h>

static void		flag_ws(t_printf *pf, t_pfopt *opt, wchar_t *wstr)
{
	const int		len = ft_wstrlen(wstr) * 4;
	char			str[len];
	int				length;

	length = ft_wstrnconv(str, wstr,
		(opt->flags & PFLAG_PRECI) ? opt->preci : len);
	margin_before(pf, opt, length);
	ft_write(pf->out, str, length);
	pf->printed += length;
	margin_after(pf, opt, length);
}

static int		strmaxlen(const char *str, int max)
{
	int				len;

	len = -1;
	while (++len < max)
	{
		if (str[len] == '\0')
			break ;
	}
	return (len);
}

void			flag_s(t_printf *pf, t_pfopt *opt)
{
	char			*str;
	int				length;

	str = va_arg(*(pf->ap), char*);
	if ((opt->format == 'S' || opt->length == pflen_l) && str != NULL)
	{
		flag_ws(pf, opt, (wchar_t*)str);
		return ;
	}
	if (str == NULL)
		str = "(null)";
	if (opt->flags & PFLAG_PRECI)
		length = strmaxlen(str, opt->preci);
	else
		length = ft_strlen(str);
	margin_before(pf, opt, length);
	pf->printed += length;
	ft_write(pf->out, str, length);
	margin_after(pf, opt, length);
}
