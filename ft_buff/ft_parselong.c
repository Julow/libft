/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:35:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_buff.h"

bool			ft_parselong(t_buff *buff, int64_t *nb)
{
	bool			negatif;

	negatif = false;
	if ((BG(buff) == '-' && (negatif = true)) || BG(buff) == '+')
		buff->i++;
	if (!IS(BG(buff), IS_DIGIT))
	{
		*nb = 0;
		return (false);
	}
	*nb = BR(buff) - '0';
	while (IS(BG(buff), IS_DIGIT))
		*nb = (*nb) * 10 + (BR(buff) - '0');
	if (negatif)
		*nb = -(*nb);
	return (true);
}
