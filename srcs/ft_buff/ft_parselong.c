/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:35:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:50:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_long			ft_parselong(t_buff *buff)
{
	t_long			nb;
	t_bool			negatif;

	negatif = false;
	nb = 0;
	if ((ft_buffget(buff) == '-' && (negatif = true))
		|| ft_buffget(buff) == '+')
		buff->i++;
	while (ft_isdigit(ft_buffget(buff)))
		nb = nb * 10 + (ft_readbuff(buff) - '0');
	return (negatif ? -nb : nb);
}
