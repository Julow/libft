/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:36:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

/*
** Free unused memory
*/
void			ft_stringfree(t_string *str)
{
	char			*tmp;

	if (str->length >= str->alloc_length)
		return ;
	tmp = MAL(char, str->length + 1);
	if (tmp == NULL)
		return ;
	str->alloc_length = str->length;
	if (str->content != NULL)
	{
		ft_memcpy(tmp, str->content, sizeof(char) * str->length);
		tmp[str->length] = '\0';
		free(str->content);
	}
	else
		ft_bzero(tmp, sizeof(char) * str->length);
	str->content = tmp;
}
