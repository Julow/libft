/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 00:47:48 by juloo             #+#    #+#             */
/*   Updated: 2016/01/04 00:40:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"

int				ft_subchr(t_sub sub, t_is mask)
{
	int				i;

	i = -1;
	while (++i < sub.length)
		if (IS(sub.str[i], mask))
			return (i);
	return (-1);
}

uint32_t		ft_subchr_e(t_sub sub, uint32_t offset, char chr)
{
	while (offset < sub.length)
	{
		if (sub.str[offset] == '\\' && (offset + 1) < sub.length)
			offset++;
		else if (sub.str[offset] == chr)
			break ;
		offset++;
	}
	return (offset);
}
