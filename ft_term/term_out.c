/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:13:33 by jaguillo          #+#    #+#             */
/*   Updated: 2017/03/01 14:26:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <unistd.h>

static void		scaned(t_term *term, uint32_t len)
{
	term->cursor_x += len;
	if (term->cursor_x >= term->width)
	{
		term->cursor_y += term->cursor_x / term->width;
		term->cursor_x = term->cursor_x % term->width;
	}
	term->scan_i += len;
}

void			term_out_scan(t_term *term)
{
	uint32_t		i;

	if (!(term->flags & TERM_LINE))
		return ;
	i = term->scan_i;
	while (i < term->out.buff_i)
	{
		if (term->out.buff[i] == '\n')
		{
			scaned(term, i - term->scan_i);
			term->cursor_y++;
			term->scan_i++;
		}
		else if (term->out.buff[i] == '\r')
		{
			scaned(term, i - term->scan_i);
			term->cursor_x = 0;
			term->scan_i++;
		}
		i++;
	}
	scaned(term, i - term->scan_i);
	if (term->cursor_y > term->content_height)
		term->content_height = term->cursor_y;
}

void			term_out_flush(t_term *term)
{
	term_out_scan(term);
	write(term->fd, term->out.buff, term->out.buff_i);
	term->out.buff_i = 0;
	term->scan_i = 0;
}
