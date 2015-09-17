/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 17:02:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

t_bool			ft_parsedouble(t_buff *buff, double *nb)
{
	t_bool			negatif;
	double			po;

	negatif = (!BIS(buff, '+') && BIS(buff, '-')) ? true : false;
	if (ft_isdigit(BG(buff)))
	{
		*nb = (double)(BR(buff) - '0');
		while (ft_isdigit(BG(buff)))
			*nb = (*nb) * 10.0 + (double)(BR(buff) - '0');
	}
	else if (BG(buff) != '.')
		return (false);
	if (BIS(buff, '.'))
	{
		po = 1.0;
		while (ft_isdigit(BG(buff)))
			*nb += ((double)(BR(buff) - '0')) / (po *= 10.0);
	}
	return (true);
}
