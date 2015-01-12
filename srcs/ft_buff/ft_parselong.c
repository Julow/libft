/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:35:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 21:07:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_long			ft_parselong(t_buff *buff)
{
	t_long			nb;
	t_bool			negatif;

	negatif = FALSE;
	nb = 0;
	if ((ft_buffget(buff) == '-' && (negatif = TRUE))
		|| ft_buffget(buff) == '+')
		buff->i++;
	while (ft_isdigit(ft_buffget(buff)))
		nb = nb * 10 + (ft_readbuff(buff) - '0');
	return (negatif ? -nb : nb);
}
