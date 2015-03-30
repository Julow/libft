/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:18:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 13:18:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoub(const char *str, t_uint *nb)
{
	int				i;

	*nb = 0;
	i = 0;
	while (ft_iswhite(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		*nb = *nb * 10 + (str[i++] - '0');
	return (i);
}
