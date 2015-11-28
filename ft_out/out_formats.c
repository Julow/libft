/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_formats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 21:15:55 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			out_transform(int flags, char *str, uint32_t len)
{
	char *const		end = str + len;

	while (str < end)
	{
		if (flags & OUT_TOUPPER && *str >= 'a' && *str <= 'z')
			*str -= 'a' - 'A';
		else if (flags & OUT_TOLOWER && *str >= 'A' && *str <= 'Z')
			*str += 'a' - 'A';
		str++;
	}
}
