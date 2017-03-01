/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:43:50 by jaguillo          #+#    #+#             */
/*   Updated: 2017/03/01 14:07:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <sys/ioctl.h>

void			term_cap_n(t_term *term, t_term_cap cap_n, t_term_cap cap_1,
					uint32_t count)
{
	if (count > TERM_CAP_AVAILABLE(term, cap_1)
			&& TERM_CAP_AVAILABLE(term, cap_n))
	{
		ft_tgoto(term, cap_n, count, 0);
		return ;
	}
	while (count-- > 0)
	{
		ft_tput(term, cap_1);
	}
}

void			ft_tclear(t_term *term)
{
	term_out_scan(term);
	ft_tcursor(term, 0, 0);
	ft_tput(term, (term->flags & TERM_LINE) ? TERM_CAP_CD : TERM_CAP_CL);
	ft_flush(&term->out);
}

void			ft_tupdate(t_term *term)
{
	struct winsize	win;

	ioctl(term->fd, TIOCGWINSZ, &win);
	term->width = MAX(win.ws_col, 1);
	term->height = MAX(win.ws_row, 1);
}

void			ft_tline(t_term *term, int32_t n)
{
	term_out_scan(term);
	if (n < 0)
		term_cap_n(term, TERM_CAP_DL_N, TERM_CAP_DL, -n);
	else if (n > 0)
		term_cap_n(term, TERM_CAP_AL_N, TERM_CAP_AL, n);
}

void			ft_tscroll(t_term *term, int32_t y)
{
	t_vec2u			cursor;

	term_out_scan(term);
	cursor = VEC2U(term->cursor_x, term->cursor_y);
	if (y < 0)
	{
		// TODO: TERM_LINE scroll using ft_tline
		ft_tcursor(term, 0, 0);
		term_cap_n(term, TERM_CAP_SR_N, TERM_CAP_SR, -y);
		term->cursor_y += y;
	}
	else if (y > 0)
	{
		ft_tcursor(term, 0, term->content_height);
		term_cap_n(term, TERM_CAP_SF_N, TERM_CAP_SF, y);
		term->cursor_y += y;
	}
	ft_tcursor(term, cursor.x, cursor.y);
}

uint32_t		ft_tcontent_height(t_term *term)
{
	if (!(term->flags & TERM_LINE))
		return (term->height);
	term_out_scan(term);
	return (term->content_height);
}
