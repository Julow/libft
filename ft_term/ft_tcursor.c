/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 13:52:02 by juloo             #+#    #+#             */
/*   Updated: 2015/12/14 13:15:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"

void			ft_tcursor(t_term *term, uint32_t x, uint32_t y)
{
	if (term->flags & TERM_FULLSCREEN)
	{
		ft_tgoto(term, g_termcaps.cm, x, y);
		return ;
	}
	if (x > term->width)
	{
		y += x / term->width;
		x = x % term->width;
	}
	while (term->cursor_y < y)
	{
		ft_tput(term, g_termcaps.cap_do);
		term->cursor_y++;
	}
	while (term->cursor_y > y)
	{
		ft_tput(term, g_termcaps.up);
		term->cursor_y--;
	}
	if (x != term->cursor_x)
	{
		term->cursor_x = x;
		ft_tgoto(term, g_termcaps.ch, 0, x);
	}
	ft_flush(&term->out);
}
