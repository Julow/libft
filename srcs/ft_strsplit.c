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

static size_t	ft_count_split(char const *s, char c)
{
	size_t			split_count;
	size_t			i;

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

char			**ft_strsplit(char const *s, char c)
{
	size_t			split_i;
	size_t			i;
	size_t			length;
	char			**split;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	split = MAL(char*, 1 + ft_count_split(s, c));
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
