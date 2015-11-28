/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 20:31:02 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_write_char(t_out *out, char c)
{
	if (out->buff_i >= out->buff_size)
		out->flush(out);
	out->buff[out->buff_i++] = c;
}
