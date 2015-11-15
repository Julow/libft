/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 20:31:12 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:31:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_write_nchar(t_out *out, char c, uint32_t n)
{
	uint32_t		tmp;

	while (true)
	{
		tmp = MIN(n, out->buff_size - out->buff_i);
		ft_memset(out->buff + out->buff_i, c, tmp);
		out->buff_i += tmp;
		n -= tmp;
		if (n == 0)
			break ;
		out->flush(out);
	}
}
