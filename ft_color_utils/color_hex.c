/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:10:11 by juloo             #+#    #+#             */
/*   Updated: 2016/05/12 23:46:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"

bool			color_hex(t_sub str, uint32_t *dst)
{
	uint32_t		offset;
	uint32_t		c;

	if (str.length > 0 && str.str[0] == '#')
		str = SUB_FOR(str, 1);
	if (str.length != 6 && str.length != 8)
		return (false);
	offset = (str.length == 6) ? 24 : 32;
	*dst = (str.length == 6) ? 0xff000000 : 0;
	while (offset > 0)
	{
		offset -= 4;
		c = *str.str++;
		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'a' && c <= 'f')
			c = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			c = c - 'A' + 10;
		else
			return (false);
		*dst |= c << offset;
	}
	return (true);
}
