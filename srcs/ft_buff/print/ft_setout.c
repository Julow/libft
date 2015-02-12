/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:33:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/12 20:34:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_setout(int fd)
{
	t_buff			*buff;

	buff = FTOUT;
	if (buff->fd != fd)
	{
		ft_flush(buff);
		buff->fd = fd;
	}
}
