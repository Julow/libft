/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_out_flush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:13:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/11 18:50:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"

#include <unistd.h>
void			term_out_flush(t_term *term)
{
	// uint32_t		i;
	// uint32_t		tmp;
	// char			c;

	// if (term->flags & TERM_LINE)
	// {
	// 	i = 0;
	// 	while (i < term->out.buff_i)
	// 	{
	// 		tmp = i;
	// 		while (true)
	// 			if ((c = term->out.buff[i++]) == '\n')
	// 			{
	// 				term->line_count += (i - tmp + term->line_offset)
	// 										/ term->width + 1;
	// 				term->line_offset = 0;
	// 				break ;
	// 			}
	// 			else if (c == '\033')
	// 			{
	// 				while (i < term->out.buff_i && !IS(term->out.buff[i++], IS_ALPHA))
	// 					tmp++;
	// 				// tmp++;
	// 			}
	// 			else if (i >= term->out.buff_i)
	// 			{
	// 				if ((term->line_offset += (i - tmp + 1)) >= term->width)
	// 				{
	// 					term->line_count += term->line_offset / term->width;
	// 					term->line_offset = term->line_offset % term->width;
	// 				}
	// 				break ;
	// 			}
	// 	}
	// }
	// write(term->fd, term->out.buff, term->out.buff_i);
	// term->out.buff_i = 0;
	//
	uint32_t		pos;
	uint32_t		i;
	uint32_t		to;

	pos = 0;
	while (pos < term->out.buff_i)
	{
		i = pos;
		to = term->width - term->line_offset + i;
		if (to > term->out.buff_i)
		{
			to = term->out.buff_i;
			term->line_offset = to - ; // TODO
		}
		else
			term->line_offset = 0;
		while (i < to)
			if (term->out.buff[i++] == '\n')
				break ;
			// color: to++
		write(term->fd, term->out.buff + pos, pos - i);
		pos = i;
	}
	term->out.buff_i = 0;
}
