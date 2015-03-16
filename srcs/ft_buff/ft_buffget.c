/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:47:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 23:29:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <unistd.h>
#include <stdlib.h>

/*
** Like ft_readbuff() but don't increment the buff index
*/
inline char		ft_buffget(t_buff *buff)
{
	if (buff->i >= buff->length)
	{
		if (buff->fd < 0)
			return (EOF);
		buff->i = 0;
		if ((buff->length = read(buff->fd, buff->data, buff->buff_len)) <= 0)
			return ((buff->fd = -1), EOF);
	}
	return (buff->data[buff->i]);
}
