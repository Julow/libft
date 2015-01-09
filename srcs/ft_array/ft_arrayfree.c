/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:37:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 20:13:37 by jaguillo         ###   ########.fr       */
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

	if (array->length + 1 >= array->alloc_length)
		return ;
	tmp = MAL(void*, array->length + 1);
	if (tmp == NULL)
		return ;
	array->alloc_length = array->length + 1;
	if (array->data != NULL)
	{
		ft_memcpy(tmp, array->data, S(void*, array->length));
		array->data[array->length] = NULL;
		free(array->data);
	}
	else
		ft_bzero(tmp, S(void*, array->length + 1));
	array->data = tmp;
}
