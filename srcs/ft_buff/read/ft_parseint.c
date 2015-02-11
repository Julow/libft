/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 10:35:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_parseint(t_buff *buff)
{
	int				nb;
	t_bool			negatif;

	negatif = false;
	nb = 0;
	if ((BG(buff) == '-' && (negatif = true))
		|| BG(buff) == '+')
		buff->i++;
	while (ft_isdigit(BG(buff)))
		nb = nb * 10 + (BR(buff) - '0');
	return (negatif ? -nb : nb);
}
