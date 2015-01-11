/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:35:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 17:35:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_long			ft_parselong(t_buff *buff)
{
	t_long			nb;
	t_bool			negatif;

	if (buff->i >= buff->length)
		return (0);
	negatif = FALSE;
	nb = 0;
	if ((B(buff) == '-' && (negatif = TRUE)) || B(buff) == '+')
		buff->i++;
	while (buff->i < buff->length && ft_isdigit(B(buff)))
		nb = nb * 10 + (buff->data[buff->i++] - '0');
	return (negatif ? -nb : nb);
}
