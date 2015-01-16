/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 17:29:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:47:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_bool			ft_stringext(t_string *str, int need)
{
	char			*tmp;
	int				len;

	need += str->length + 1;
	if (need < str->alloc_length)
		return (true);
	len = str->alloc_length - 1;
	while (need >= len)
		len += STRING_CHUNK;
	if ((tmp = MAL(char, len)) == NULL)
		return (false);
	str->alloc_length = len;
	if (str->content != NULL)
	{
		ft_memmove(tmp, str->content, str->length);
		ft_bzero(tmp + str->length, len - str->length);
		free(str->content);
	}
	else
		ft_bzero(tmp, len);
	str->content = tmp;
	return (true);
}
