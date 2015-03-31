/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 15:40:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 19:54:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			write_long(t_out *out, t_long n)
{
	char			nb[PUTLONG_BUFF];
	t_uint			i;

	i = PUTLONG_BUFF;
	if (n <= 0)
	{
		nb[--i] = '0' - (n % 10);
		n /= -10;
	}
	while (n != 0)
	{
		nb[--i] = '0' + (n % 10);
		n /= 10;
	}
	ft_write(out, nb + i, PUTLONG_BUFF - i);
}

void			flag_d(t_printf *pf, t_pfopt *opt)
{
	t_long			d;
	int				len;

	if (opt->format == 'D')
		d = (t_long)va_arg(*(pf->ap), long int);
	else
		d = get_arg(pf, opt);
	len = ft_numlen(d, 10);
	if (d < 0 && opt->flags & PFLAG_ZERO)
		ft_writechar(pf->out, '-');
	else if (d >= 0 && opt->flags & PFLAG_PLUS && ++len)
		ft_writechar(pf->out, '+');
	else if (opt->flags & PFLAG_SPACE && d >= 0 && ++len)
		ft_writechar(pf->out, ' ');
	if (opt->flags & PFLAG_PRECI && (opt->preci -= len) > 0)
		len += opt->preci;
	margin_before(pf, opt, len);
	if (d < 0 && !(opt->flags & PFLAG_ZERO))
		ft_writechar(pf->out, '-');
	if (opt->flags & PFLAG_PRECI)
		ft_writenchar(pf->out, '0', opt->preci);
	pf->printed += len;
	write_long(pf->out, d);
	margin_after(pf, opt, len);
}
