/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 20:38:37 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_in.h"

bool			ft_read(t_in *in, char *dst, uint32_t n)
{
	uint32_t		i;
	uint32_t		tmp;

	i = 0;
	while (true)
	{
		tmp = in->buff_len - in->buff_i;
		if (tmp > n - i)
			tmp = n - i;
		if (dst != NULL)
			ft_memcpy(dst + i, in->buff + in->buff_i, tmp);
		in->buff_i += tmp;
		i += tmp;
		if (i == n)
			return (true);
		if (!ft_in_refresh(in))
			break ;
	}
	return (false);
}
