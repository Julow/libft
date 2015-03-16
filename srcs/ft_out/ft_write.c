/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:23:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/17 00:30:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_write(t_out *out, const char *data, t_uint len)
{
	t_uint			free_buff;

	while (1)
	{
		free_buff = out->length - out->i;
		if (len <= free_buff)
			break ;
		ft_write(out, data, free_buff);
		ft_flush(out);
		data += free_buff;
		len -= free_buff;
	}
	ft_memcpy(out->buff + out->i, data, len);
	out->i += len;
}
