/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 17:33:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_parsedouble(t_buff *buff)
{
	double			nb;
	double			part;
	t_bool			negatif;

	negatif = (B(buff) == '-') ? TRUE : FALSE;
	if (B(buff) == '-' || B(buff) == '+')
		buff->i++;
	nb = 0.0;
	while (ft_isdigit(B(buff)))
		nb = nb * 10 + (buff->data[buff->i++] - '0');
	if (B(buff) == '.' || B(buff) == ',')
	{
		part = 0.0;
		while (ft_isdigit(buff->data[++buff->i]))
			;
		while (ft_isdigit(buff->data[--buff->i]))
			part = (part + (B(buff) - '0')) / 10.0;
		nb += part;
	}
	return (negatif ? -nb : nb);
}
