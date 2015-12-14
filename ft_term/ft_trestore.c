/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trestore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:50:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/14 13:52:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"
#include <termios.h>

void			ft_trestore(t_term *term, bool enable)
{
	if (enable)
	{
		tcsetattr(0, TCSADRAIN, term->term_config);
		if (term->flags & TERM_FULLSCREEN)
		{
			ft_tput(term, g_termcaps.ti, 0, 0);
			ft_flush(&(term->out));
		}
	}
	else
	{
		if (term->flags & TERM_FULLSCREEN)
		{
			ft_tput(term, g_termcaps.te, 0, 0);
			ft_flush(&(term->out));
		}
		tcsetattr(0, TCSADRAIN, term->term_config + sizeof(struct termios));
	}
	term->cursor_x = 0;
	term->cursor_y = 0;
}
