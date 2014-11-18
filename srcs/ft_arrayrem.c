/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:09 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:08:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_arrayrem(t_array *array, int index)
{
	void			*tmp;
	int				i;

	tmp = array->data[index];
	array->data[index] = NULL;
	i = index;
	while (++i < array->length)
		array->data[i - 1] = array->data[i];
	array->length--;
	return (tmp);
}
