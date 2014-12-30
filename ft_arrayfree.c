/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:37:19 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:37:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Free unused memory
*/
void			ft_arrayfree(t_array *array)
{
	void			**tmp;

	if (array->length >= array->alloc_length)
		return ;
	tmp = MAL(void*, array->length);
	array->alloc_length = array->length;
	if (array->data != NULL)
	{
		ft_memcpy(tmp, array->data, array->length * sizeof(void*));
		free(array->data);
	}
	else
		ft_bzero(tmp, sizeof(void*) * array->length);
	array->data = tmp;
}
