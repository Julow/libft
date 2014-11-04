/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:16:53 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:16:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_bytes;

	s_bytes = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		s_bytes[i] = 0;
		i++;
	}
}
