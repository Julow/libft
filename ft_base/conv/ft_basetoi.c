/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/ft_basetoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 23:54:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/07 23:54:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong			ft_basetoi(const char *str, const char *base)
{
	int				i;
	int				base_len;
	t_ulong			nb;

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
