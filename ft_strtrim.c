/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:09:39 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 15:09:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t			start;
	size_t			to;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	to = ft_strlen(s) - 1;
	while ((s[to] == ' ' || s[to] == '\n' || s[to] == '\t') && start < to)
		to--;
	return (ft_strsub(s, start, to - start + 1));
}
