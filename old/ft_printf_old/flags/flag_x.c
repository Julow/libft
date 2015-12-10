/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:13:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			flag_x(t_printf *pf, t_pfopt *opt)
{
	uint64_t			nb;
	int				len;
	bool			upper;

	nb = get_unsigned_arg(pf, opt);
	len = ft_unumlen(nb, 16);
	upper = (opt->flags & PFLAG_UPPER || opt->format == 'X') ? true : false;
	if (opt->flags & PFLAG_ALT && nb != 0)
		len += 2;
	margin_before(pf, opt, len);
	if (opt->flags & PFLAG_ALT && nb != 0)
		ft_writestr(pf->out, upper ? "0X" : "0x");
	ft_writebase(pf->out, nb, upper ? BASE_16 : BASE_16_LOWER);
	pf->printed += len;
	margin_after(pf, opt, len);
}
