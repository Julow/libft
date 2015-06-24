/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:23:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/24 22:35:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dstr.h"

void			ft_writechar(t_out *out, char c)
{
	if (out->flags & OUT_DSTR)
	{
		ft_dstradd_char((t_dstr*)out->buff, c);
		return ;
	}
	if (out->i >= out->length)
		ft_flush(out);
	out->buff[out->i++] = c;
}
