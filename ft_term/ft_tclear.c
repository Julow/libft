/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:54:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/09 18:30:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"

void			ft_tclear(t_term *term)
{
	if (!(term->flags & TERM_LINE))
	{
		ft_putstr(&(term->out), tgetstr("cl", NULL), -1);
		ft_flush(&(term->out));
		return ;
	}
	if (term->line_count > 0)
		ft_putstr(&(term->out),
			tgoto(tgetstr("UP", NULL), term->line_count, 0), -1);
	ft_putstr(&(term->out), tgoto(tgetstr("ch", NULL), 0, 0), -1);
	ft_putstr(&(term->out), tgetstr("cd", NULL), -1);
}
