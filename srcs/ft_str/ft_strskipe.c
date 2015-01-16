/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 23:08:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:48:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the len of 'str' using only char of 'skip'
** Allow char from 'str' to be escaped with '\'
*/
t_uint			ft_strskipe(const char *str, const char *skip)
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
		else if (ft_strchr(skip, str[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}
