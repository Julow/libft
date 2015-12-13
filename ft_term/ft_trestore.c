/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trestore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:50:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/13 18:05:11 by juloo            ###   ########.fr       */
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
			ft_tput(term, TERMCAP_ti);
			ft_flush(&(term->out));
		}
	}
	else
	{
		if (term->flags & TERM_FULLSCREEN)
		{
			ft_tput(term, TERMCAP_te);
			ft_flush(&(term->out));
		}
		tcsetattr(0, TCSADRAIN, term->term_config + sizeof(struct termios));
	}
	term->line_count = 0;
	term->line_offset = 0;
}
