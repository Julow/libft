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

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	char			nb[10];
	int				tmp;
	t_uint			i;
	t_uint			len;

	tmp = n;
	len = (n < 0) ? 2 : 1;
	while ((tmp /= 10) != 0)
		len++;
	tmp = n;
	i = len;
	while (i-- > 0)
	{
		nb[i] = '0' + ((n < 0) ? -(tmp % 10) : tmp % 10);
		tmp /= 10;
	}
	if (n < 0)
		nb[0] = '-';
	ft_putlstr_fd(nb, len, fd);
}
