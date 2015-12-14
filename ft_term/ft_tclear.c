/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:54:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/14 13:52:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"

void			ft_tclear(t_term *term)
{
	ft_tcursor(term, 0, 0);
	if (term->flags & TERM_LINE)
		ft_tput(term, g_termcaps.cd, 0, 0);
	else
		ft_tput(term, g_termcaps.cl, 0, 0);
	ft_flush(&term->out);
}
