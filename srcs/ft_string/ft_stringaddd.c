/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:41:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/02 16:32:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add the string representation of 'd'
*/
static void		fix_precision(t_string *str)
{
	int				i;

	i = str->length;
	while (str->content[--i] == '9')
		str->content[i] = '0';
	str->content[i]++;
}

void			ft_stringaddd(t_string *str, double d, int preci)
{
	int				i;
	int				tmp;

	ft_stringaddid(str, (preci <= 0) ? d + 0.5 : d);
	if (preci <= 0 || ISNAN(d))
		return ;
	if (!ft_stringext(str, preci + 1))
		return ;
	ft_stringaddc(str, '.');
	d -= (int)d;
	i = -1;
	while (++i < preci)
	{
		d *= 10;
		if ((i + 1) >= preci)
			d += 0.5;
		tmp = (int)d;
		if (tmp >= 10)
		{
			tmp = tmp % 10;
			fix_precision(str);
		}
		str->content[str->length++] = '0' + tmp;
		d -= tmp;
	}
}
