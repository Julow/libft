/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:57:14 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/06 13:57:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strnadd(char **str, char const *add, size_t len)
{
	size_t			i;
	size_t			j;
	char			*tmp;

	tmp = *str;
	*str = ft_strnew(ft_strlen(tmp) + len + 1);
	i = 0;
	if (tmp != NULL)
	{
		while (tmp[i] != '\0')
		{
			(*str)[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	j = 0;
	while (j < len)
	{
		(*str)[i + j] = add[j];
		j++;
	}
}
