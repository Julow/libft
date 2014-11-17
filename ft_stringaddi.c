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
** =============
** Return FALSE(0) if the malloc fail, TRUE(1) otherwise
*/
t_bool			ft_stringaddi(t_string *str, int nbr)
{
	int				tmp;
	int				i;

	tmp = nbr;
	i = ((tmp < 0) ? 2 : 1);
	while ((tmp /= 10) != 0)
		i++;
	if (!ft_stringext(str, i))
		return (FALSE);
	str->length += i;
	i = str->length - 1;
	tmp = nbr;
	while (nbr != 0)
	{
		str->content[i--] = '0' + ((nbr < 0) ? -(nbr % 10) : nbr % 10);
		nbr /= 10;
	}
	if (tmp < 0)
		str->content[i] = '-';
	return (TRUE);
}
