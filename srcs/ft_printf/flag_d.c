/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 15:40:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 16:44:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_d(t_printf *pf, t_pfopt *opt)
{
	t_long			d;
	int				len;

	d = get_arg(pf, opt);
	len = ft_numlen(d, 10);
	margin_before(pf, opt, len);
	pf->printed += len;
	ft_writeint(pf->out, d);
	margin_after(pf, opt, len);
}
