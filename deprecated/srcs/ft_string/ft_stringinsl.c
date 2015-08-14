/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringinsl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:12:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** Insert 'l' char of 'ins' in the string 'str' at 'index'
** =============
** Return FALSE(0) if the malloc fail, TRUE(1) otherwise
*/
void			ft_stringinsl(t_string *str, const char *ins, int index, int l)
{
	if (!ft_stringext(str, l))
		return ;
	ft_memmove(str->content + index + l, str->content + index,
		str->length - index);
	ft_memmove(str->content + index, ins, l);
	str->length += l;
}
