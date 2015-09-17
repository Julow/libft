/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:54:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 12:54:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, t_uint len)
{
	t_uint			i;
	char			eosrc;

	i = 0;
	eosrc = 0;
	while (i < len)
	{
		if (eosrc == 0 && src[i] == '\0')
			eosrc = 1;
		dst[i] = (eosrc == 1) ? '\0' : src[i];
		i++;
	}
	return (dst);
}
