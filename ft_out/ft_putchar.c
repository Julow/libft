/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:46:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_putchar(t_out *out, char c)
{
	ft_putpad_left(out, 1);
	if (SHOULD_TRANSFORM(out->flags))
		out_transform(out->flags, &c, 1);
	if (out->buff_i >= out->buff_size)
		out->flush(out);
	out->buff[out->buff_i++] = c;
	ft_putpad_right(out, 1);
}
