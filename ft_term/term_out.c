/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:13:33 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/24 17:02:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <unistd.h>

void			term_out_scan(t_term *term)
{
	uint32_t		tmp;

	if (!(term->flags & TERM_LINE))
		return ;
	while (true)
	{
		tmp = ft_subfind_c(SUB(term->out.buff, term->out.buff_i), '\n',
				term->scan_i);
		term->cursor_x += tmp - term->scan_i;
		if (term->cursor_x >= term->width)
		{
			term->cursor_y += term->cursor_x / term->width;
			term->cursor_x = term->cursor_x % term->width;
		}
		term->scan_i = tmp;
		if (tmp >= term->out.buff_i)
			break ;
		term->cursor_y++;
		term->cursor_x = 0;
		term->scan_i++;
	}
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
