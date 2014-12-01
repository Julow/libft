/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:40:20 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/01 13:40:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putnchar(char c, int n)
{
	char			chars[n];
	int				i;

	i = -1;
	while (++i < n)
		chars[i] = c;
	write(1, chars, n);
}
