/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:20:09 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 17:20:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str_add(char *str, char add)
{
	size_t			i;
	size_t			length;
	char			*tmp;

	length = ft_strlen(str);
	tmp = str;
	str = ft_memalloc(sizeof(char) * (length + 2));
	i = 0;
	while (tmp[i] != 0)
	{
		str[i] = tmp[i];
		i++;
	}
	str[length] = add;
	free(tmp);
	return (str);
}

char			*ft_itoa(int n)
{
	char			*a;
	int				tmp;
	int				div;

	a = ft_strnew(0);
	if (n < 0)
	{
		n *= -1;
		a = ft_str_add(a, '-');
	}
	tmp = n;
	div = 0;
	while (tmp >= 1)
	{
		tmp /= 10;
		div = (div == 0) ? 1 : div * 10;
	}
	while (div > 0)
	{
		a = ft_str_add(a, '0' + (n / div % 10));
		div /= 10;
	}
	return ((n == 0) ? ft_str_add(a, '0') : a);
}
