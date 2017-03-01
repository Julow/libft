/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 13:52:02 by juloo             #+#    #+#             */
/*   Updated: 2017/03/01 14:16:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"

/*
** TODO: RI_N, ND, LE_N, LE may be removed if CH is available
** TODO: check ll, cr, cv
*/

static void		tcursor_relative(t_term *term, uint32_t x, uint32_t y)
{
	if (term->cursor_y < y)
		term_cap_n(term, TERM_CAP_DO_N, TERM_CAP_DO, y - term->cursor_y);
	else
		term_cap_n(term, TERM_CAP_UP_N, TERM_CAP_UP, term->cursor_y - y);
	if (x != term->cursor_x && TERM_CAP_AVAILABLE(term, TERM_CAP_CH))
		ft_tgoto(term, TERM_CAP_CH, x, 0);
	else if (term->cursor_x < x)
		term_cap_n(term, TERM_CAP_RI_N, TERM_CAP_ND, x - term->cursor_x);
	else
		term_cap_n(term, TERM_CAP_LE_N, TERM_CAP_LE, term->cursor_x - x);
}

/*
** TODO: fill BC ('le') and UP ('up') when using 'cm'
*/
void			ft_tcursor(t_term *term, uint32_t x, uint32_t y)
{
	term_out_scan(term);
	if (term->flags & TERM_FULLSCREEN && x == 0 && y == 0
		&& TERM_CAP_AVAILABLE(term, TERM_CAP_HO))
		ft_tput(term, TERM_CAP_HO);
	else if (term->flags & TERM_FULLSCREEN
		&& TERM_CAP_AVAILABLE(term, TERM_CAP_CM))
		ft_tgoto(term, TERM_CAP_CM, x, y);
	else
		tcursor_relative(term, x, y);
	term->cursor_y = y;
	if (term->cursor_y > term->content_height)
		term->content_height = term->cursor_y;
	term->cursor_x = x;
}
