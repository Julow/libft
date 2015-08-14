/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraykil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include <stdlib.h>

void			ft_arraykil(void *array, void (*f)(void *data))
{
	if (f != NULL)
		ft_arrayclr((t_array*)array, f);
	if (array != NULL)
	{
		if (((t_array*)array)->data != NULL)
			free(((t_array*)array)->data);
		free(array);
	}
}
