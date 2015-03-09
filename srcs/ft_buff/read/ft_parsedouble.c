/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 00:21:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_parsedouble(t_buff *buff)
{
	t_bool			negatif;
	double			nb;
	double			po;

	negatif = (!BIS(buff, '+') && BIS(buff, '-')) ? true : false;
	nb = 0.0;
	while (ft_isdigit(BG(buff)))
		nb = nb * 10.0 + (double)(BR(buff) - '0');
	if (BIS(buff, '.') && (po = 1.0))
		while (ft_isdigit(BG(buff)))
			nb += ((double)(BR(buff) - '0')) / (po *= 10.0);
	return (negatif ? -nb : nb);
}
