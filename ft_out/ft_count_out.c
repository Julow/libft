/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 22:39:03 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 18:14:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_count_out.h"

char			g_countout_buff[COUNT_OUT_BUFF] = {};

void			count_out_flush(t_count_out *out)
{
	out->count += out->out.buff_i;
	out->out.buff_i = 0;
}
