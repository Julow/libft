/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:33:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:56:35 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_internal.h"

/*
** Add the string representation of 'nbr' in the string 'str'
*/
void			ft_stringaddi(t_string *str, int nbr)
{
	char			nb[PUTNBR_BUFF];
	t_uint			i;

	i = PUTNBR_BUFF;
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
	ft_stringaddl(str, nb + i, PUTNBR_BUFF - i);
}
