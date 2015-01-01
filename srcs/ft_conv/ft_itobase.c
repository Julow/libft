/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/ft_itobase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 23:53:57 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/07 23:53:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itobase(t_ulong nb, const char *base)
{
	int				base_len;
	char			*str;
	int				i;
	t_ulong			tmp;

	base_len = ft_strlen(base);
	if (nb == 0 || base_len == 0)
		return (ft_strdup("0"));
	tmp = nb;
	i = 1;
	while ((tmp /= base_len) != 0)
		i++;
	if ((str = MAL(char, i + 1)) == NULL)
		return (NULL);
	str[i] = '\0';
	tmp = nb;
	while (--i >= 0)
	{
		str[i] = base[tmp % base_len];
		tmp /= base_len;
	}
	return (str);
}
