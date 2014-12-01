/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:45:19 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/01 13:45:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putnchar_fd(char c, int n, int fd)
{
	char			chars[n];
	int				i;

	i = -1;
	while (++i < n)
		chars[i] = c;
	write(fd, chars, n);
}
