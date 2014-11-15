/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraykil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:57 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:08:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_arraykil(t_array *array, void (*f)(void *data))
{
	if (f != NULL)
		ft_arrayclr(array, f);
	free(array->data);
	free(array);
}
