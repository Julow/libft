/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:13:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 19:35:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_o(t_printf *pf, t_pfopt *opt)
{
	t_ulong			nb;
	int				len;

	if (opt->format == 'O')
		nb = (t_long)(va_arg(*(pf->ap), unsigned long int));
	else
		nb = get_unsigned_arg(pf, opt);
	len = ft_unumlen(nb, 8);
	if (opt->flags & PFLAG_ALT && nb != 0)
		len++;
	if (opt->flags & PFLAG_PRECI && (opt->preci -= len) > 0)
		len += opt->preci;
	margin_before(pf, opt, len - opt->preci);
	if (opt->flags & PFLAG_ALT && nb != 0)
		ft_writechar(pf->out, '0');
	if (opt->flags & PFLAG_PRECI)
		ft_writenchar(pf->out, '0', opt->preci);
	ft_writebase(pf->out, nb, BASE_8);
	pf->printed += len;
	margin_after(pf, opt, len - opt->preci);
}
