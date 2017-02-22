/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trestore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:50:28 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/22 17:17:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"
#include <termios.h>

void			ft_trestore(t_term *term, bool enable)
{
	if (enable)
	{
		tcsetattr(0, TCSADRAIN, &term->term_config[0]);
		if (term->flags & TERM_FULLSCREEN)
		{
			ft_tput(term, TERM_CAP_TI);
			ft_flush(&(term->out));
		}
	}
	else
	{
		if (term->flags & TERM_FULLSCREEN)
		{
			ft_tput(term, TERM_CAP_TE);
			ft_flush(&(term->out));
		}
		tcsetattr(0, TCSADRAIN, &term->term_config[1]);
	}
	term->cursor_x = 0;
	term->cursor_y = 0;
}
