/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_out_flush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:13:33 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/22 15:44:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <unistd.h>

static uint32_t	scan_nl(t_term *term, char const *buff, uint32_t i)
{
	uint32_t const	end = term->out.buff_i;
	uint32_t		tmp;
	char			c;

	tmp = i;
	while (i < end)
		if ((c = buff[i++]) == '\n')
		{
			term->cursor_y += (i - tmp + term->cursor_x) / term->width + 1;
			term->cursor_x = 0;
			return (i);
		}
		else if (c == '\033')
		{
			while (i < end && !IS(buff[i++], IS_ALPHA))
				tmp++;
		}
	if ((term->cursor_x += (i - tmp)) >= term->width)
	{
		term->cursor_y += (term->cursor_x - 1) / term->width;
		term->cursor_x = term->cursor_x % term->width;
	}
	return (i);
}

void			term_out_flush(t_term *term)
{
	uint32_t		i;

	if (term->flags & TERM_LINE)
	{
		i = 0;
		while (i < term->out.buff_i)
			i = scan_nl(term, term->out.buff, i);
	}
	write(term->fd, term->out.buff, term->out.buff_i);
	term->out.buff_i = 0;
}
