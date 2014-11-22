/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 18:55:47 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/22 18:55:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_arrayswap(t_array *array, int i1, int i2)
{
	void			*tmp;

	tmp = array->data[i1];
	array->data[i1] = array->data[i2];
	array->data[i2] = tmp;
}
