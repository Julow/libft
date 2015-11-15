/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:31:54 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 16:17:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include <unistd.h>

static char		g_ftout_buff[FTOUT_BUFF] = {};
t_ftout			g_ftout = {OUT(g_ftout_buff, FTOUT_BUFF, &ftout_flush), 1};

void			ftout_flush(t_ftout *out)
{
	if (out->out.buff_i > 0)
	{
		write(out->fd, out->out.buff, out->out.buff_i);
		out->out.buff_i = 0;
	}
}

void			ft_out(int fd)
{
	if (fd == g_ftout.fd)
		return ;
	if (g_ftout.out.buff_i > 0)
		ftout_flush(&g_ftout);
	g_ftout.fd = fd;
}
