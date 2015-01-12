/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:47:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:16:42 by jaguillo         ###   ########.fr       */
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
		if ((buff->length = read(buff->fd, buff->data, BUFF_SIZE)) <= 0)
			return (free(buff->data), (*buff = BUFF(NULL, 0, 0)), EOF);
	}
	return (buff->data[buff->i]);
}
