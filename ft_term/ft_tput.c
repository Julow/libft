/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:00:37 by juloo             #+#    #+#             */
/*   Updated: 2017/02/24 14:14:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <termcap.h>

/*
** TODO: padding
*/

void			ft_tput_raw(t_term *term, t_sub str)
{
	term_out_scan(term);
	if ((term->out.buff_size - term->out.buff_i) < str.length)
		ft_flush(&term->out);
	ft_write(&term->out, str.str, str.length);
	term->scan_i = term->out.buff_i;
}

void			ft_tput(t_term *term, t_term_cap cap)
{
	if (TERM_CAP_AVAILABLE(term, cap))
		ft_tput_raw(term, ft_sub(term->term_caps[cap], 0, -1));
}

void			ft_tgoto(t_term *term, t_term_cap cap, int x, int y)
{
	if (TERM_CAP_AVAILABLE(term, cap))
		ft_tput_raw(term,
				ft_sub(tgoto(term->term_caps[cap], y, x), 0, -1));
}
