/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 21:58:38 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:46:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_flush(t_out *out)
{
	out->flush(out);
}

void			ft_putendl(t_out *out)
{
	if (out->buff_i >= out->buff_size)
		out->flush(out);
	out->buff[out->buff_i++] = '\n';
	out->flush(out);
}
