/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraychr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int				ft_arraychr(t_array *array, const void *chr)
{
	int				i;

	i = 0;
	while (i < array->length)
	{
		if (array->data[i] == chr)
			return (i);
		i++;
	}
	return (-1);
}
