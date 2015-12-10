/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 18:08:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			flag_p(t_printf *pf, t_pfopt *opt)
{
	uint64_t			nb;
	int				len;
	bool			upper;

	nb = (uint64_t)va_arg(*(pf->ap), void*);
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
