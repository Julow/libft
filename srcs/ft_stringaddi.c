/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:33:05 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:33:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add the string representation of 'nbr' in the string 'str'
*/
void			ft_stringaddi(t_string *str, int nbr)
{
	char			nb[10];
	int				tmp;
	t_uint			i;
	t_uint			len;

	tmp = nbr;
	len = (nbr < 0) ? 2 : 1;
	while ((tmp /= 10) != 0)
		len++;
	tmp = nbr;
	i = len;
	while (i-- > 0)
	{
		nb[i] = '0' + ((nbr < 0) ? -(tmp % 10) : tmp % 10);
		tmp /= 10;
	}
	if (nbr < 0)
		nb[0] = '-';
	ft_stringaddl(str, nb, len);
}
