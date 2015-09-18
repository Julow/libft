/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 01:53:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/18 15:04:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_rr(t_printf *pf, t_pfopt *opt)
{
	char			*str;
	int				i;
	int				length;

	str = va_arg(*(pf->ap), char*);
	if (str == NULL)
		str = "";
	if (opt->flags & PFLAG_PRECI)
		length = opt->preci;
	else
		length = ft_strlen(str);
	margin_before(pf, opt, length);
	i = -1;
	while (++i < length)
		ft_writechar(pf->out, IS(str[i], IS_PRINT) ? str[i] : '.');
	pf->printed += length;
	margin_after(pf, opt, length);
}
