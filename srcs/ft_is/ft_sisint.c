/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:36:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 22:36:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MIN_INT_STR		"-2147483648"
#define MAX_INT_STR		"2147483647"

t_bool			ft_sisint(const char *s)
{
	int				len;

	len = (*s == '-') ? 1 : 0;
	while (ft_isdigit(s[len]))
		len++;
	if (s[len] != '\0' || (len == 1 && *s == '-'))
		return (false);
	if (*s == '-' && len == 11 && ft_memcmp(s, MIN_INT_STR, 11) > 0)
		return (false);
	if (*s != '-' && len == 10 && ft_memcmp(s, MAX_INT_STR, 10) > 0)
		return (false);
	if (len > 10)
		return (false);
	return (true);
}
