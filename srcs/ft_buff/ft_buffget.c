/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:47:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/17 22:45:10 by jaguillo         ###   ########.fr       */
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
		if (BEOF(buff) || BSTR(buff))
			return (EOF);
		buff->i = 0;
		if ((buff->length = read(BFD(buff), buff->data, buff->buff_len)) <= 0)
		{
			buff->fd |= BIT(BF_EOF);
			return (EOF);
		}
	}
	return (buff->data[buff->i]);
}
