/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcskipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 00:00:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:50:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the len of 'str' using char of 'skip' as stop
** Allow char from 'str' to be escaped with '\'
*/
t_uint			ft_strcskipe(const char *str, const char *skip)
{
	t_uint			i;
	t_bool			escaped;

	i = 0;
	escaped = false;
	while (str[i] != '\0')
	{
		if (escaped)
			escaped = false;
		else if (str[i] == '\\')
			escaped = true;
		else if (ft_strchr(skip, str[i]) != NULL)
			break ;
		i++;
	}
	return (i);
}
