/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:09:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:48:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_bool			ft_arrayext(t_array *array, int need)
{
	void			**tmp;
	int				len;

	need += array->length + 1;
	if (need < array->alloc_length)
		return (true);
	len = array->alloc_length - 1;
	while (need >= len)
		len += ARRAY_CHUNK;
	if ((tmp = MAL(void*, len)) == NULL)
		return (false);
	array->alloc_length = len;
	if (array->data != NULL)
	{
		ft_memmove(tmp, array->data, S(void*, array->length));
		ft_bzero(tmp + array->length, S(void*, len - array->length));
		free(array->data);
	}
	else
		ft_bzero(tmp, len);
	array->data = tmp;
	return (true);
}
