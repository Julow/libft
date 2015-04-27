/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:37:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/27 15:33:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wstrnconv(char *buff, wchar_t *wstr, int n)
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
