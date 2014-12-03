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

void			ft_arrayext(t_array *array, int need)
{
	void			**tmp;
	int				i;

	need += array->length;
	if (need < array->alloc_length)
		return ;
	i = array->alloc_length;
	while (need >= i)
		i += 24;
	tmp = (void**)malloc(sizeof(void*) * i);
	array->alloc_length = i;
	if (array->data != NULL)
	{
		i = -1;
		while (++i < array->length)
			tmp[i] = array->data[i];
		i--;
		while (++i < array->alloc_length)
			tmp[i] = NULL;
		ft_gbfree(array->data);
	}
	array->data = tmp;
}
