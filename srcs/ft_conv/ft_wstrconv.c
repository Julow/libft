/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:45:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wstrconv(char *buff, int *wstr)
{
	int				i;
	int				len;

	len = 0;
	i = -1;
	while (wstr[++i] != 0)
		len += ft_widetoa(buff + len, wstr[i]);
	return (len);
}
