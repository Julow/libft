/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:43:50 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/23 17:52:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <sys/ioctl.h>

void			term_cap_n(t_term *term, t_term_cap cap_n, t_term_cap cap_1,
					uint32_t count)
{
	if (count > 1 && TERM_CAP_AVAILABLE(term, cap_n))
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
	if (n < 0)
		term_cap_n(term, TERM_CAP_DL_N, TERM_CAP_DL, -n);
	else if (n > 0)
		term_cap_n(term, TERM_CAP_AL_N, TERM_CAP_AL, n);
}
