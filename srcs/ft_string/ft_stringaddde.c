/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddde.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:43:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/02 16:33:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add the scientific representation of 'd'
** X.XXXXXXe+XX
*/
void			ft_stringaddde(t_string *str, double d, int preci)
{
	int				p;

	if (ISNAN(d))
	{
		ft_stringadd(str, "nan");
		return ;
	}
	if (d < 0 && (d = -1) == -1)
		ft_stringaddc(str, '-');
	p = 0;
	while (d > 10)
	{
		d /= 10;
		p++;
	}
	while (d < 1)
	{
		d *= 10;
		p--;
	}
	ft_stringaddd(str, d, preci);
	ft_stringadd(str, (p < 0) ? "e-" : "e+");
	if (p > -10 && p < 10)
		ft_stringaddc(str, '0');
	ft_stringaddi(str, (p < 0) ? -p : p);
}
