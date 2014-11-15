/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:42 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:08:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_arrayclr(t_array *array, void (*f)(void *data))
{
	int				i;

	i = -1;
	while (++i < array->length)
		f(array->data[i]);
}
