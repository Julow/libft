/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:13:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 17:47:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_b(t_printf *pf, t_pfopt *opt)
{
	t_ulong			nb;
	int				len;
	t_bool			upper;

	nb = get_unsigned_arg(pf, opt);
	len = ft_unumlen(nb, 2);
	upper = (opt->flags & PFLAG_UPPER || opt->format == 'B') ? true : false;
	if (opt->flags & PFLAG_ALT)
		len += 2;
	margin_before(pf, opt, len);
	if (opt->flags & PFLAG_ALT)
		ft_writestr(pf->out, upper ? "0B" : "0b");
	ft_writebase(pf->out, nb, BASE_2);
	pf->printed += len;
	margin_after(pf, opt, len);
}
