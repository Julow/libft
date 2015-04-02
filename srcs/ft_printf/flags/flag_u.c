/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 18:30:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 18:35:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			ft_writeulong(t_out *out, t_ulong n)
{
	char			nb[PUTLONG_BUFF];
	t_uint			i;

	i = PUTLONG_BUFF;
	if (n == 0)
		nb[--i] = '0';
	while (n != 0)
	{
		nb[--i] = '0' + (n % 10);
		n /= 10;
	}
	ft_write(out, nb + i, PUTLONG_BUFF - i);
}

void			flag_u(t_printf *pf, t_pfopt *opt)
{
	t_ulong			d;
	int				len;

	if (opt->format == 'U')
		d = (t_ulong)va_arg(*(pf->ap), unsigned long int);
	else
		d = get_unsigned_arg(pf, opt);
	len = ft_unumlen(d, 10);
	margin_before(pf, opt, len);
	pf->printed += len;
	ft_writeulong(pf->out, d);
	margin_after(pf, opt, len);
}
