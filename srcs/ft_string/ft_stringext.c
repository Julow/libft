/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 17:29:19 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 17:29:20 by jaguillo         ###   ########.fr       */
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
		return (TRUE);
	len = str->alloc_length - 1;
	while (need >= len)
		len += 24;
	if ((tmp = MAL(char, len)) == NULL)
		return (FALSE);
	str->alloc_length = len;
	if (str->content != NULL)
	{
		ft_memmove(tmp, str->content, sizeof(char) * str->length);
		ft_bzero(tmp + str->length, len - str->length);
		free(str->content);
	}
	else
		ft_bzero(tmp, len);
	str->content = tmp;
	return (TRUE);
}
