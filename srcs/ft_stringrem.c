/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringrem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:27:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:27:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove 'len' char in the string 'str' from 'index'
*/
void			ft_stringrem(t_string *str, int index, int len)
{
	if (index >= str->length)
		return ;
	if ((index + len) > str->length)
		len = str->length - index;
	str->length -= len;
	ft_memmove(str->content + index, str->content + index + len,
		str->length - index);
	ft_bzero(str->content + str->length, len);
}
