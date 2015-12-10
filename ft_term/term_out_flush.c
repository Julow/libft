/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_out_flush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:13:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 13:12:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_internal.h"
#include <unistd.h>

void			term_out_flush(t_term *term)
{
	uint32_t		i;
	uint32_t		tmp;

	if (term->flags & TERM_LINE)
	{
		i = 0;
		while (i < term->out.buff_i)
		{
			tmp = i;
			while (i < term->out.buff_i)
				if (term->out.buff[i++] == '\n')
				{
					term->line_count++;
					break ;
				}
			term->line_count += (i - tmp) / term->width;
		}
	}
	write(term->fd, term->out.buff, term->out.buff_i);
	term->out.buff_i = 0;
}
