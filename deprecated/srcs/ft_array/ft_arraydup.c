/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 12:50:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_array			*ft_arraydup(const t_array *array)
{
	t_array			*dup;

	dup = ft_arraynew();
	ft_arrayext(dup, array->length);
	ft_memcpy(dup->data, array->data, array->length * sizeof(void*));
	dup->length = array->length;
	return (dup);
}
