/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:20:09 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 17:20:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*str;
	int				tmp;
	size_t			i;

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
