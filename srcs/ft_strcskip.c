/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcskip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 23:58:29 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/30 23:58:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the len of 'str' using char of 'skip' as stop
*/
t_uint			ft_strcskip(const char *str, const char *skip)
{
	t_uint			i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(skip, str[i]) == NULL)
		i++;
	return (i);
}
