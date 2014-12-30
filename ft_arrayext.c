/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:09:19 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:09:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_arrayext(t_array *array, int need)
{
	void			**tmp;
	int				len;

	need += array->length + 1;
	if (need < array->alloc_length)
		return ;
	len = array->alloc_length - 1;
	while (need >= len)
		len += 24;
	tmp = MAL(void*, len);
	array->alloc_length = len;
	if (array->data != NULL)
	{
		ft_memmove(tmp, array->data, sizeof(void*) * array->length);
		ft_bzero(tmp + array->length, len - array->length);
		free(array->data);
	}
	else
		ft_bzero(tmp, len);
	array->data = tmp;
}
