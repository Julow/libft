/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:42 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_buff.h"

t_bool			ft_parsedouble(t_buff *buff, double *nb)
{
	t_bool			negatif;
	double			po;

	negatif = (!BIS(buff, '+') && BIS(buff, '-')) ? true : false;
	if (IS(BG(buff), IS_DIGIT))
	{
		*nb = (double)(BR(buff) - '0');
		while (IS(BG(buff), IS_DIGIT))
			*nb = (*nb) * 10.0 + (double)(BR(buff) - '0');
	}
	else if (BG(buff) != '.')
		return (false);
	if (BIS(buff, '.'))
	{
		po = 1.0;
		while (IS(BG(buff), IS_DIGIT))
			*nb += ((double)(BR(buff) - '0')) / (po *= 10.0);
	}
	return (true);
}
