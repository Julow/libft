/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:35:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void		write_w(t_out *out, t_pfopt *opt, uint8_t *data, int len)
{
	char			*base;

	base = (opt->flags & PFLAG_UPPER) ? BASE_16 : BASE_16_LOWER;
	while (len-- > 0)
	{
		if (*data < 16)
			ft_writechar(out, '0');
		ft_writebase(out, *data, base);
		if (len > 0)
		{
			if (opt->flags & PFLAG_SPACE)
				ft_writechar(out, ' ');
			if (opt->flags & PFLAG_GROUP && ((uint64_t)data & 3) == 0)
				ft_writechar(out, ' ');
		}
		data++;
	}
}

void			flag_w(t_printf *pf, t_pfopt *opt)
{
	int				len;
	int				data_len;
	uint8_t			*data;

	data = va_arg(*(pf->ap), uint8_t*);
	data_len = (opt->flags & PFLAG_PRECI) ? opt->preci : ft_strlen((char*)data);
	len = (opt->flags & PFLAG_SPACE) ? data_len * 3 - 1 : data_len * 2;
	if (opt->flags & PFLAG_GROUP)
		len += ((((uint64_t)data & 3) <= 0) ? data_len + 1 : data_len) / 4;
	margin_before(pf, opt, len);
	write_w(pf->out, opt, data, data_len);
	pf->printed += len;
	margin_after(pf, opt, len);
}
