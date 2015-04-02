/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 18:08:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 19:57:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_p(t_printf *pf, t_pfopt *opt)
{
	t_ulong			nb;
	int				len;
	t_bool			upper;

	nb = (t_ulong)va_arg(*(pf->ap), void*);
	len = (nb == 0) ? 3 : ft_unumlen(nb, 16) + 2;
	upper = (opt->flags & PFLAG_UPPER || opt->format == 'P') ? true : false;
	if (opt->flags & PFLAG_ALT)
		len += 1;
	if (!(opt->flags & PFLAG_ZERO))
		margin_before(pf, opt, len);
	if (opt->flags & PFLAG_ALT)
		ft_writechar(pf->out, '*');
	ft_writestr(pf->out, upper ? "0X" : "0x");
	if (opt->flags & PFLAG_ZERO)
		margin_before(pf, opt, len);
	ft_writebase(pf->out, nb, upper ? BASE_16 : BASE_16_LOWER);
	pf->printed += len;
	margin_after(pf, opt, len);
}
