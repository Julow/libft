/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:54:33 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 17:54:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <unistd.h>

int				ft_putnbr_fd(int n, int fd)
{
	char			nb[PUTNBR_BUFF];
	t_uint			i;

	i = PUTNBR_BUFF;
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
	return (write(fd, nb + i, PUTNBR_BUFF - i));
}
