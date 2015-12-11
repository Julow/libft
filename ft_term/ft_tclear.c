/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:54:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/11 17:48:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"

void			ft_tclear(t_term *term)
{
	if (!(term->flags & TERM_LINE))
	{
		ft_putsub(&term->out, term->termcaps[TERMCAP_cl]);
		ft_flush(&term->out);
		return ;
	}
	while (term->line_count > 0)
	{
		ft_putsub(&term->out, term->termcaps[TERMCAP_up]);
		term->line_count--;
	}
	term->line_offset = 0;
	ft_putsub(&term->out, term->termcaps[TERMCAP_ch0]);
	ft_putsub(&term->out, term->termcaps[TERMCAP_cd]);
	ft_flush(&term->out);
}
