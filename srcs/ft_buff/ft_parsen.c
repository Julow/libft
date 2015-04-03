/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 15:50:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 15:52:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_parsen(t_buff *buff, char *dst, int len)
{
	int				i;

	i = -1;
	while (++i < len && !BEOF(buff))
		dst[i] = BR(buff);
	if (i == len)
		return (true);
	return (false);
}
