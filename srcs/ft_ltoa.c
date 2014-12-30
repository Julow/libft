/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/ft_ltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 23:56:23 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/07 23:56:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa(t_long n)
{
	char			*str;
	t_long			tmp;
	t_uint			i;

	tmp = n;
	i = (tmp < 0) ? 2 : 1;
	while ((tmp /= 10) != 0)
		i++;
	str = ft_strnew(i);
	tmp = n;
	while (i-- > 0)
	{
		str[i] = '0' + ((n < 0) ? -(n % 10) : n % 10);
		n /= 10;
	}
	if (tmp < 0)
		str[0] = '-';
	return (str);
}
