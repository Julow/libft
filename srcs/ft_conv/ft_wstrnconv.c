/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:37:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:45:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wstrnconv(char *buff, int *wstr, int n)
{
	int				i;
	int				tmp;
	int				len;

	len = 0;
	i = -1;
	while (wstr[++i] != 0)
	{
		tmp = ft_widetoa(buff + len, wstr[i]);
		if ((tmp + len) > n)
			break ;
		len += tmp;
	}
	return (len);
}
