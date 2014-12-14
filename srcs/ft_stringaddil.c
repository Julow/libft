/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:39:09 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/09 23:39:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stringaddil(t_string *str, t_long nbr)
{
	char			nb[21];
	t_long			tmp;
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
