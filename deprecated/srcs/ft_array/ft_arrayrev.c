/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 18:57:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void			ft_arrayrev(t_array *array)
{
	int				i;
	int				middle;

	middle = array->length / 2;
	i = -1;
	while (++i < middle)
		ft_arrayswap(array, i, array->length - i - 1);
}
