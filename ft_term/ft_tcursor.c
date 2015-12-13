/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 13:52:02 by juloo             #+#    #+#             */
/*   Updated: 2015/12/13 23:46:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"

void			ft_tcursor(t_term *term, int x, int y)
{
	x += term->line_offset;
	while (x < 0)
	{
		x += term->width;
		y--;
	}
	if (x > (int)term->width)
	{
		y -= x / term->width;
		x = x % term->width;
	}
	term->line_count += y;
	term->line_offset = x;
	while (y < 0)
	{
		ft_tput(term, TERMCAP_up);
		y++;
	}
	while (y > 0)
	{
		ft_tput(term, TERMCAP_do);
		y--;
	}
	ft_tgoto(term, TERMCAP_ch, 0, x);
}
