/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:28:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 15:28:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_array_add(char ***array, char *add)
{
	size_t			i;
	size_t			length;
	char			**tmp;

	length = 0;
	while ((*array)[length] != '\0')
		length++;
	tmp = *array;
	(*array) = ft_memalloc(sizeof(char*) * (length + 2));
	i = 0;
	while (tmp[i] != 0)
	{
		(*array)[i] = tmp[i];
		i++;
	}
	(*array)[length] = add;
	free(tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			length;
	char			**split;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	split = (char**)ft_memalloc(sizeof(char*));
	while (s[i] != '\0')
	{
		length = 0;
		while (s[i + length] != c && s[i + length] != '\0')
			length++;
		ft_array_add(&split, ft_strsub(s, i, length));
		i += length;
		while (s[i] == c)
			i++;
	}
	return (split);
}
