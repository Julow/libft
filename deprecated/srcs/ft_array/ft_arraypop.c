/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 23:48:22 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 01:51:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

inline void		*ft_arraypop(t_array *array)
{
	void			*tmp;

	if (array->length > 0)
	{
		array->length--;
		tmp = array->data[array->length];
		array->data[array->length] = NULL;
	}
	else
		tmp = NULL;
	return (tmp);
}
