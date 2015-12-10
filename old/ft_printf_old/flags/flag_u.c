/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 18:30:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void		ft_writeulong(t_out *out, uint64_t n)
{
	char			nb[PUTLONG_BUFF];
	uint32_t			i;

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
	uint64_t			d;
	int				len;

	if (opt->format == 'U')
		d = (uint64_t)va_arg(*(pf->ap), unsigned long int);
	else
		d = get_unsigned_arg(pf, opt);
	len = ft_unumlen(d, 10);
	margin_before(pf, opt, len);
	pf->printed += len;
	ft_writeulong(pf->out, d);
	margin_after(pf, opt, len);
}
