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

t_bool			ft_arrayext(t_array *array)
{
	void			**tmp;
	int				i;

	if (array->length < array->alloc_length)
		return (TRUE);
	i = array->alloc_length;
	while (array->length >= i)
		i += 16;
	tmp = MAL(void*, i);
	if (tmp == NULL)
		return (FALSE);
	array->alloc_length = i;
	if (array->data != NULL)
	{
		i = -1;
		while (++i < array->length)
			tmp[i] = array->data[i];
		i--;
		while (++i < array->alloc_length)
			tmp[i] = NULL;
		free(array->data);
	}
	array->data = tmp;
	return (TRUE);
}
