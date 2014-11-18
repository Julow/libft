/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:07:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:07:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_arrayadd(t_array *array, void *add)
{
	if (!ft_arrayext(array))
		return (FALSE);
	array->data[array->length] = add;
	array->length++;
	return (TRUE);
}
