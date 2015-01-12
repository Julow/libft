/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:07:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:29:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_arrayadd(t_array *array, void *add)
{
	if (!ft_arrayext(array, 1))
		return ;
	array->data[array->length] = add;
	array->length++;
}
