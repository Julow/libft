/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:37:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/15 16:18:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

int				ft_wstrnconv(char *buff, wchar_t const *wstr, int n)
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
