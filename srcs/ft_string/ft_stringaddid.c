/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:40:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/02 16:33:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add the string representation of the integer part of 'nbr'
*/
void			ft_stringaddid(t_string *str, double nbr)
{
	int				tmp;
	int				length;

	if (ISNAN(nbr))
	{
		ft_stringadd(str, "nan");
		return ;
	}
	length = ((nbr < 0) ? 2 : 1);
	while ((nbr /= 10) > 1)
		length++;
	if (!ft_stringext(str, length))
		return ;
	if (nbr < 0)
		str->content[str->length++] = '-';
	length += str->length;
	while (str->length < length)
	{
		nbr *= 10;
		tmp = (int)nbr;
		str->content[str->length++] = '0' + tmp;
		nbr -= tmp;
	}
}
