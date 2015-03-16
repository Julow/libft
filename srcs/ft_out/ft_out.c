/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 23:08:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/17 00:29:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			g_ftout_buff[FTOUT_BUFF] = DB(FTOUT_BUFF, 0);
t_out			g_ftout = OUT(1, g_ftout_buff, FTOUT_BUFF);

void			ft_out(int fd)
{
	t_out			*out;

	out = FTOUT;
	if (out->fd != fd)
	{
		ft_flush(out);
		out->fd = fd;
	}
}
