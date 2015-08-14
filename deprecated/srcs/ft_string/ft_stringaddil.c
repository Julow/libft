/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:39:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:56:51 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_internal.h"

void			ft_stringaddil(t_string *str, t_long nbr)
{
	char			nb[PUTLONG_BUFF];
	t_uint			i;

	i = PUTLONG_BUFF;
	nb[0] = (nbr < 0) ? '-' : '+';
	if (nbr <= 0)
	{
		nb[--i] = '0' - (nbr % 10);
		nbr /= -10;
	}
	while (nbr != 0)
	{
		nb[--i] = '0' + (nbr % 10);
		nbr /= 10;
	}
	if (nb[0] == '-')
		nb[--i] = '-';
	ft_stringaddl(str, nb + i, PUTLONG_BUFF - i);
}
