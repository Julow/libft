/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_refresh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 20:38:37 by juloo             #+#    #+#             */
/*   Updated: 2016/02/02 16:19:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_in.h"

bool			ft_in_refresh(t_in *in)
{
	if (in->buff_i < in->buff_len)
		return (true);
	if (in->refresh == NULL || !in->refresh(in))
		return (false);
	return (BOOL_OF(in->buff_i < in->buff_len));
}
