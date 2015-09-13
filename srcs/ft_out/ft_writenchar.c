/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:21:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/13 20:34:00 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dstr.h"

void			ft_writenchar(t_out *out, char c, int n)
{
	int				free_buff;

	if (out->flags & OUT_DSTR)
	{
		ft_memset(ft_dstrspan((t_dstr*)out->buff, -1, -1, 0), c, n);
		return ;
	}
	while (n > 0)
	{
		free_buff = out->length - out->i;
		if (free_buff <= 0)
		{
			ft_flush(out);
			continue ;
		}
		if (n < free_buff)
			free_buff = n;
		ft_memset(out->buff + out->i, c, free_buff);
		out->i += free_buff;
		n -= free_buff;
	}
}
