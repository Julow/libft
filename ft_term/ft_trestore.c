/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trestore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:50:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/09 20:00:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"

void			ft_trestore(t_term *term, t_bool enable)
{
	if (enable)
	{
		tcsetattr(0, TCSADRAIN, term->termios);
		if (term->flags & TERM_FULLSCREEN)
		{
			ft_putstr(&(term->out), tgetstr("ti", NULL), -1);
			ft_flush(&(term->out));
		}
	}
	else
	{
		if (term->flags & TERM_FULLSCREEN)
		{
			ft_putstr(&(term->out), tgetstr("te", NULL), -1);
			ft_flush(&(term->out));
		}
		tcsetattr(0, TCSADRAIN, term->termios + 1);
	}
	term->line_count = 0;
}
