/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraykilf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:10:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include <stdlib.h>

void			ft_arraykilf(void *array)
{
	ft_arraykil(array, &free);
}
