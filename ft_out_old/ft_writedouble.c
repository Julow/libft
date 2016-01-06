/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writedouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 00:16:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_out.h"

static void		writedi(t_out *out, double d)
{
	uint64_t			tmp;

	if (d < 1)
		return ;
	writedi(out, d / 10);
	tmp = (uint64_t)d;
	d -= tmp;
	ft_writechar(out, tmp % 10 + '0');
}

static void		writedd(t_out *out, double d, int preci)
{
	uint64_t			tmp;

	while (preci--)
	{
		d *= 10;
		if (preci == 0)
			d += 0.5;
		tmp = (uint64_t)d;
		d -= tmp;
		ft_writechar(out, tmp % 10 + '0');
	}
}

void			ft_writedouble(t_out *out, double d, int preci)
{
	if (ISNAN(d))
	{
		ft_writestr(out, "(NaN)");
		return ;
	}
	if (d < 0)
	{
		ft_writechar(out, '-');
		d = -d;
	}
	if (preci <= 0)
	{
		writedi(out, d + 0.5);
		return ;
	}
	if (d < 1)
		ft_writechar(out, '0');
	else
		writedi(out, d);
	ft_writechar(out, '.');
	writedd(out, d, preci);
}
