/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:23:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/13 20:36:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dstr.h"

void			ft_write(t_out *out, const char *data, t_uint len)
{
	t_uint			free_buff;

	if (out->flags & OUT_DSTR)
	{
		ft_dstradd((t_dstr*)out->buff, SUB(data, len));
		return ;
	}
	while (len > 0)
	{
		free_buff = out->length - out->i;
		if (free_buff <= 0)
		{
			ft_flush(out);
			continue ;
		}
		if (len < free_buff)
			free_buff = len;
		ft_memcpy(out->buff + out->i, data, free_buff);
		out->i += free_buff;
		len -= free_buff;
		data += free_buff;
	}
}
