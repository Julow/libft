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
#include <stdlib.h>

void			ft_putnbr_fd(int n, int fd)
{
	char			*tmp;

	tmp = ft_itoa(n);
	ft_putstr_fd(tmp, fd);
	free(tmp);
}
