/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/13 22:01:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_write_sub(t_out *out, t_sub sub)
{
	uint32_t		tmp;
	uint32_t		i;

	out_before(out, sub.length);
	i = 0;
	while (true)
	{
		tmp = MIN(sub.length - i, out->buff_size - out->buff_i);
		ft_memcpy(out->buff + out->buff_i, sub.str + i, tmp);
		if (SHOULD_TRANSFORM(out->flags))
			out_transform(out->flags, out->buff + out->buff_i, tmp);
		out->buff_i += tmp;
		i += tmp;
		if (i >= sub.length)
			break ;
		out->flush(out);
	}
	out_after(out, sub.length);
}
