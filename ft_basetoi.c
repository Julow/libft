/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 23:54:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t			ft_basetoi(const char *str, const char *base)
{
	int				i;
	int				base_len;
	uint64_t			nb;

	base_len = ft_strlen(base);
	nb = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		nb *= base_len;
		nb += ft_strchri(base, str[i]);
	}
	return (nb);
}
