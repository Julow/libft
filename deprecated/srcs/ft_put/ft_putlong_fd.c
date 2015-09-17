/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 18:51:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/01 18:51:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <unistd.h>

int				ft_putlong_fd(t_long n, int fd)
{
	char			nb[PUTLONG_BUFF];
	t_uint			i;

	i = PUTLONG_BUFF;
	nb[0] = (n < 0) ? '-' : '+';
	if (n <= 0)
	{
		nb[--i] = '0' - (n % 10);
		n /= -10;
	}
	while (n != 0)
	{
		nb[--i] = '0' + (n % 10);
		n /= 10;
	}
	if (nb[0] == '-')
		nb[--i] = '-';
	return (write(fd, nb + i, PUTLONG_BUFF - i));
}
