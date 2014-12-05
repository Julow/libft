/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:36:24 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:36:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Free unused memory
*/
void			ft_stringfree(t_string *str)
{
	char			*tmp;
	int				i;

	if (str->length >= str->alloc_length)
		return ;
	tmp = MAL(char, str->length);
	str->alloc_length = str->length;
	if (str->content != NULL)
	{
		i = -1;
		while (++i < str->length)
			tmp[i] = str->content[i];
		free(str->content);
	}
	str->content = tmp;
}
