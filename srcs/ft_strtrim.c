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

char			*ft_strtrim(const char *s)
{
	t_uint			start;
	t_uint			to;
	t_uint			s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start == s_len)
		return (ft_strnew(0));
	to = s_len - 1;
	while (s[to] == ' ' || s[to] == '\n' || s[to] == '\t')
		to--;
	return (ft_strsub(s, start, to - start + 1));
}
