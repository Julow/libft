/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:01 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:08:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_arrayins(t_array *array, void *ins, int index)
{
	int				i;

	if (index >= array->length)
		return (ft_arrayset(array, ins, index));
	if (!ft_arrayext(array))
		return (FALSE);
	i = array->length - 1;
	while (--i >= index)
		array->data[i + 1] = array->data[i];
	array->data[index] = ins;
	array->length++;
	return (TRUE);
}
