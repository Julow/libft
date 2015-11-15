/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:44:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_putnchar(t_out *out, char c, uint32_t n)
{
	ft_putpad_left(out, n);
	if (SHOULD_TRANSFORM(out->flags))
		out_transform(out->flags, &c, 1);
	ft_write_nchar(out, c, n);
	ft_putpad_right(out, n);
}
