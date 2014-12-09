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
	t_long			tmp;
	int				i;

	tmp = nbr;
	i = ((tmp < 0) ? 2 : 1);
	while ((tmp /= 10) != 0)
		i++;
	ft_stringext(str, i);
	str->length += i;
	i = str->length - 1;
	str->content[i] = '0';
	tmp = nbr;
	while (nbr != 0)
	{
		str->content[i--] = '0' + ((nbr < 0) ? -(nbr % 10) : nbr % 10);
		nbr /= 10;
	}
	if (tmp < 0)
		str->content[i] = '-';
}
