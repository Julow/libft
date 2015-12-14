/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:00:37 by juloo             #+#    #+#             */
/*   Updated: 2015/12/14 11:57:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <termcap.h>

void			ft_tgoto(t_term *term, t_term_caps cap, int x, int y)
{
	char const		*str;
	uint32_t		len;

	str = tgoto(term->termcaps[cap].str, x, y);
	len = ft_strlen(str);
	if ((term->out.buff_size - term->out.buff_i) < len)
		ft_flush(&term->out);
	ft_write(&term->out, str, len);
}

void			ft_tput(t_term *term, t_term_caps cap)
{
	t_sub const		*sub = term->termcaps + cap;

	if ((term->out.buff_size - term->out.buff_i) < (uint32_t)sub->length)
		ft_flush(&term->out);
	ft_write(&term->out, sub->str, sub->length);
}
