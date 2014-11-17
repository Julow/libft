/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringinsl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:12:09 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:29:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Insert 'len' char of 'ins' in the string 'str' at 'index'
** =============
** Return FALSE(0) if the malloc fail, TRUE(1) otherwise
*/
t_bool			ft_stringinsl(t_string *str, char *ins, int index, int len)
{
	int				i;

	if (!ft_stringext(str, len))
		return (FALSE);
	i = str->length;
	while (--i >= index)
		str->content[len + i] = str->content[i];
	i = len;
	while (--i >= 0)
		str->content[index + i] = ins[i];
	str->length += len;
	return (TRUE);
}
