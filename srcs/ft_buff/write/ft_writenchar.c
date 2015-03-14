/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:21:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 00:46:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_writenchar(t_buff *buff, char c, int n)
{
	int				free_buff;

	while (true)
	{
		free_buff = buff->length - buff->i;
		if (n <= free_buff)
			break ;
		ft_writenchar(buff, c, free_buff);
		ft_flush(buff);
		n -= free_buff;
	}
	ft_memset(buff->data + buff->i, c, n);
	buff->i += n;
}
