/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void			ft_arrayclr(void *array, void (*f)(void *data))
{
	int				i;

	i = -1;
	if (f != NULL)
		while (++i < ((t_array*)array)->length)
			f(((t_array*)array)->data[i]);
	ft_bzero(((t_array*)array)->data, S(void*, ((t_array*)array)->length));
	((t_array*)array)->length = 0;
}
