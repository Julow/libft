/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:00:37 by juloo             #+#    #+#             */
/*   Updated: 2017/02/22 19:11:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <termcap.h>

/*
** TODO: padding
*/

static void		put_term_cap(t_term *term, char const *str)
{
	uint32_t const	len = ft_strlen(str);

	if ((term->out.buff_size - term->out.buff_i) < len)
		ft_flush(&term->out);
	ft_write(&term->out, str, len);
}

void			ft_tput(t_term *term, t_term_cap cap)
{
	if (TERM_CAP_AVAILABLE(term, cap))
		put_term_cap(term, term->term_caps[cap]);
}

void			ft_tgoto(t_term *term, t_term_cap cap, int x, int y)
{
	if (TERM_CAP_AVAILABLE(term, cap))
		put_term_cap(term, tgoto(term->term_caps[cap], y, x));
}
