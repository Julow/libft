/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 20:36:10 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:36:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_write(t_out *out, char const *str, uint32_t len)
{
	uint32_t		i;
	uint32_t		tmp;

	i = 0;
	while (true)
	{
		tmp = MIN(len - i, out->buff_size - out->buff_i);
		ft_memcpy(out->buff + out->buff_i, str + i, tmp);
		if (SHOULD_TRANSFORM(out->flags))
			out_transform(out->flags, out->buff + out->buff_i, tmp);
		out->buff_i += tmp;
		i += tmp;
		if (i >= len)
			break ;
		out->flush(out);
	}
}
