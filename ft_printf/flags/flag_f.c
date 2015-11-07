/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 14:24:19 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 15:13:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include "ft_dstr.h"
#include "ft_out.h"

void			flag_f(t_printf *pf, t_pfopt *opt)
{
	static t_dstr	tmp_str = DSTR0();
	double			d;
	int				preci;
	t_out			sout;

	d = get_float_arg(pf, opt);
	preci = (opt->flags & PFLAG_PRECI) ? opt->preci : 6;
	ft_dstrclear(&tmp_str);
	sout = DSTR_OUT(&tmp_str);
	ft_writedouble(&sout, d, preci);
	margin_before(pf, opt, tmp_str.length);
	ft_write(pf->out, tmp_str.str, tmp_str.length);
	margin_after(pf, opt, tmp_str.length);
}
