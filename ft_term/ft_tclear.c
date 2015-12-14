/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:54:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/14 13:15:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"

void			ft_tclear(t_term *term)
{
	ft_tcursor(term, 0, 0);
	if (term->flags & TERM_LINE)
		ft_tput(term, g_termcaps.cd);
	else
		ft_tput(term, g_termcaps.cl);
}
