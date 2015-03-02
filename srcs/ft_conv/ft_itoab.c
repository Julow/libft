/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 12:38:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/02 12:40:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Write the string representation of 'n' in 'buff' and return the len
*/
int				ft_itoab(int n, char *buff)
{
	int				len;
	int				tmp;

	len = (n < 0) ? 2 : 1;
	if (n < 0)
		*buff = '-';
	else if (n == 0)
		*buff = '0';
	tmp = n;
	while ((tmp /= 10) != 0)
		len++;
	buff += len;
	*(buff--) = '\0';
	if (n <= 0)
	{
		*(buff--) = '0' + (-n % 10);
		n /= -10;
	}
	while (n != 0)
	{
		*(buff--) = '0' + (n % 10);
		n /= 10;
	}
	return (len);
}
