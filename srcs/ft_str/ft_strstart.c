/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 17:46:12 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 17:46:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstart(char *str, const char *start)
{
	while (*str == *start && *start != '\0')
	{
		str++;
		start++;
	}
	if (*start != '\0')
		return (NULL);
	return (str);
}
