/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:26:09 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:26:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_stringchr(t_string *str, char c)
{
	int				i;

	i = 0;
	while (i < str->length)
	{
		if (str->content[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
