/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_out_flush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:13:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/12 01:56:08 by juloo            ###   ########.fr       */
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
			term->line_count += (i - tmp + term->line_offset) / term->width + 1;
			term->line_offset = 0;
			return (i);
		}
		else if (c == '\033')
		{
			while (i < end && !IS(buff[i++], IS_ALPHA))
				tmp++;
		}
	if ((term->line_offset += (i - tmp)) >= term->width)
	{
		term->line_count += (term->line_offset - 1) / term->width;
		term->line_offset = term->line_offset % term->width;
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
