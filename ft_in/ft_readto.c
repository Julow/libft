/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 20:38:37 by juloo             #+#    #+#             */
/*   Updated: 2015/12/05 21:30:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_in.h"

t_bool			ft_readto_char(t_in *in, char end, t_dstr *dst)
{
	uint32_t		i;

	while (true)
	{
		i = in->buff_i;
		while (i < in->buff_len)
		{
			if (in->buff[i] == end)
				break ;
		}
		if (dst != NULL)
			ft_dstradd(dst, SUB(in->buff + in->buff_i, i - in->buff_i));
		in->buff_i = i;
		if (i < in->buff_len)
			return (true);
		if (!ft_in_refresh(in))
			break ;
	}
	return (false);
}

t_bool			ft_readto_if(t_in *in, t_is end, t_dstr *dst)
{
	uint32_t		i;

	while (true)
	{
		i = in->buff_i;
		while (i < in->buff_len)
		{
			if (IS(in->buff[i], end))
				break ;
		}
		if (dst != NULL)
			ft_dstradd(dst, SUB(in->buff + in->buff_i, i - in->buff_i));
		in->buff_i = i;
		if (i < in->buff_len)
			return (true);
		if (!ft_in_refresh(in))
			break ;
	}
	return (false);
}
