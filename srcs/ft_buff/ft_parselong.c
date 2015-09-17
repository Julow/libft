/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:35:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 17:01:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

t_bool			ft_parselong(t_buff *buff, t_long *nb)
{
	t_bool			negatif;

	negatif = false;
	if ((BG(buff) == '-' && (negatif = true)) || BG(buff) == '+')
		buff->i++;
	if (!ft_isdigit(BG(buff)))
		return ((*nb = 0), false);
	*nb = BR(buff) - '0';
	while (ft_isdigit(BG(buff)))
		*nb = (*nb) * 10 + (BR(buff) - '0');
	if (negatif)
		*nb = -(*nb);
	return (true);
}
