/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:18:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoub(const char *str, uint32_t *nb)
{
	int				i;

	*nb = 0;
	i = 0;
	while (IS(str[i], IS_WHITE))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		*nb = *nb * 10 + (str[i++] - '0');
	return (i);
}
