/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 13:52:02 by juloo             #+#    #+#             */
/*   Updated: 2015/12/14 12:36:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"

void			ft_tcursor(t_term *term, uint32_t x, uint32_t y)
{
	if (term->flags & TERM_FULLSCREEN)
	{
		ft_tgoto(term, TERMCAP_cm, x, y);
		return ;
	}
	if (x > term->width)
	{
		y += x / term->width;
		x = x % term->width;
	}
	while (term->cursor_y < y)
	{
		ft_tput(term, TERMCAP_do);
		term->cursor_y++;
	}
	while (term->cursor_y > y)
	{
		ft_tput(term, TERMCAP_up);
		term->cursor_y--;
	}
	if (x != term->cursor_x)
	{
		term->cursor_x = x;
		ft_tgoto(term, TERMCAP_ch, 0, x);
	}
	ft_flush(&term->out);
}
