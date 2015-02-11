/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:23:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/11 21:44:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_write(t_buff *buff, const char *data, t_uint len)
{
	t_uint			free_buff;

	while (1)
	{
		free_buff = buff->length - buff->i;
		if (len <= free_buff)
			break ;
		ft_write(buff, data, free_buff);
		ft_flush(buff);
		data += free_buff;
		len -= free_buff;
	}
	ft_memcpy(buff->data + buff->i, data len);
}
