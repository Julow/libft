/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:38:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:45:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_widetoa(char *buff, int w)
{
	if (w < 0x80)
		return (*buff = ((w & 0x7F) | 0), 1);
	else if (w < 0x800)
	{
		*(buff++) = ((w >> 6) & 0x1F) | 0xC0;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else if (w < 0x10000)
	{
		*(buff++) = ((w >> 12) & 0xF) | 0xE0;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (w < 0x110000)
	{
		*(buff++) = ((w >> 18) & 0x7) | 0xF0;
		*(buff++) = ((w >> 12) & 0x3F) | 0x80;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}
