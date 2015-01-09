/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 20:11:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_arrayrem(t_array *array, int index)
{
	void			*tmp;

	tmp = array->data[index];
	array->data[index] = NULL;
	array->length--;
	if (index < array->length)
	{
		ft_memmove(array->data + index, array->data + index + 1, sizeof(void*));
		array->data[array->length] = NULL;
	}
	return (tmp);
}
