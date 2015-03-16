/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:21:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/17 00:23:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_writenchar(t_out *out, char c, int n)
{
	int				free_buff;

	while (true)
	{
		free_buff = out->length - out->i;
		if (n <= free_buff)
			break ;
		ft_writenchar(out, c, free_buff);
		ft_flush(out);
		n -= free_buff;
	}
	ft_memset(out->buff + out->i, c, n);
	out->i += n;
}
