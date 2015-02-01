/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:35:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 10:35:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_long			ft_parselong(t_buff *buff)
{
	t_long			nb;
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
