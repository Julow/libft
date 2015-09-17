/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 23:08:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/30 23:08:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the len of 'str' using only char of 'skip'
*/
t_uint			ft_strskip(const char *str, const char *skip)
{
	t_uint			i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(skip, str[i]) != NULL)
		i++;
	return (i);
}
