/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:21:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/24 22:36:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dstr.h"

void			ft_writenchar(t_out *out, char c, int n)
{
	int				free_buff;

	if (out->flags & OUT_DSTR)
	{
		ft_dstradd_nchar((t_dstr*)out->buff, c, n);
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
