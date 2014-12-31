/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:07:51 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:07:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_arrayset(t_array *array, void *set, int index)
{
	if (array->length <= index)
		array->length = index + 1;
	if (!ft_arrayext(array, 1))
		return ;
	array->data[index] = set;
}
