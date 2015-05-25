/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 00:48:50 by juloo             #+#    #+#             */
/*   Updated: 2015/05/26 00:54:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcount(char const *str, t_is mask)
{
	int				count;

	while (IS(*str, mask))
		str++;
	count = 0;
	while (*str != '\0')
	{
		count++;
		while (!IS(*str, mask) && *str != '\0')
			str++;
		while (IS(*str, mask))
			str++;
	}
	return (count);
}
