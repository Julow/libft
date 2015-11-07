/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 01:09:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 17:13:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_out.h"

int				num_len(t_uint num)
{
	int				len;

	len = (num == 0) ? 1 : 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void			ft_hexdump(const void *data, t_uint len)
{
	t_uint			i;
	t_uint			wlen;
	int				max;

	max = num_len(len - 1);
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
