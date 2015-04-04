/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 01:09:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/04 02:54:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			ft_hexdump(const void *data, t_uint len)
{
	t_uint			i;
	t_uint			wlen;
	int				max;

	max = ft_unumlen((t_ulong)(len - 1), 10);
	i = MIN(len, 16) - (((t_ulong)data & 15) + 3);
	P("%0*d   % '50.*w   %16.*R\n", max, 0, i, data, i, data);
	while (i < len)
	{
		wlen = MIN(len - i, 16);
		P("%0*d   % '-50.*w   %.*R\n", max, i, wlen, data + i, wlen, data + i);
		i += wlen;
	}
	FL;
}
