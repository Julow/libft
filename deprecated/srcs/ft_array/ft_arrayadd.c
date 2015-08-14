/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:07:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

inline void		ft_arrayadd(t_array *array, void *add)
{
	if (!ft_arrayext(array, 1))
		return ;
	array->data[array->length] = add;
	array->length++;
}
