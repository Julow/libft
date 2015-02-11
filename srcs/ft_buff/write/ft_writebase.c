/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writebase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:23:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/11 22:07:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			ft_writebase(t_buff *buff, t_ulong n, const char *base)
{
	const t_uint	base_len = ft_strlen(base);
	char			nb[PUTBASE_BUFF];
	t_uint			i;

	i = PUTBASE_BUFF;
	while (n != 0)
	{
		nb[--i] = base[(n % base_len)];
		n /= base_len;
	}
	ft_write(buff, nb + i, PUTBASE_BUFF - i);
}
