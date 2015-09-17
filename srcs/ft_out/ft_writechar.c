/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:23:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 17:05:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_out.h"
#include "ft_dstr.h"

void			ft_writechar(t_out *out, char c)
{
	if (out->flags & OUT_DSTR)
	{
		ft_dstradd((t_dstr*)out->buff, SUB(&c, 1));
		return ;
	}
	if (out->i >= out->length)
		ft_flush(out);
	out->buff[out->i++] = c;
}
