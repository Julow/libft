/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:00:37 by juloo             #+#    #+#             */
/*   Updated: 2015/12/14 13:50:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <termcap.h>

void			ft_tput(t_term *term, t_termcaps cap, int x, int y)
{
	t_sub			sub;

	sub = term->termcaps[cap->id];
	if (cap->tgoto)
		sub = ft_sub(tgoto(sub.str, x, y), 0, -1);
	if ((term->out.buff_size - term->out.buff_i) < (uint32_t)sub.length)
		ft_flush(&term->out);
	ft_write(&term->out, sub.str, sub.length);
}
