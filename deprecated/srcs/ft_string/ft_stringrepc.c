/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringrepc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:35:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** Replace all occurence of the char 'c' in the string 'str' by the char 'r'
*/
void			ft_stringrepc(t_string *str, char c, char r)
{
	int				i;

	i = -1;
	while (++i < str->length)
	{
		if (str->content[i] == c)
			str->content[i] = r;
	}
}
