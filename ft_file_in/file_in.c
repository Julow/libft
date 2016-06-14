/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:46:06 by juloo             #+#    #+#             */
/*   Updated: 2016/06/14 19:19:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"

#include <stdlib.h>
#include <unistd.h>

void		ft_in_close(t_file_in *in)
{
	if (in->opened)
		close(in->fd);
	free(in);
}

bool		file_in_refresh(t_file_in *in)
{
	int			len;

	len = read(in->fd, in->buff, in->buff_size);
	in->in.buff_i = 0;
	if (len <= 0)
	{
		in->in.buff_len = 0;
		return (false);
	}
	in->in.buff_len = len;
	return (true);
}
