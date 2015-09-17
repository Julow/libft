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

static t_uint	ft_count_split(const char *s, char c)
{
	t_uint			split_count;
	t_uint			i;

	split_count = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		split_count++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (split_count);
}

char			**ft_strsplit(const char *s, char c)
{
	t_uint			split_i;
	t_uint			i;
	t_uint			length;
	char			**split;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if ((split = MAL(char*, 1 + ft_count_split(s, c))) == NULL)
		return (NULL);
	split_i = 0;
	while (s[i] != '\0')
	{
		length = 0;
		while (s[i + length] != c && s[i + length] != '\0')
			length++;
		split[split_i++] = ft_strsub(s, i, length);
		i += length;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	split[split_i] = NULL;
	return (split);
}
