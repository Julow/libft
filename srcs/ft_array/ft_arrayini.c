/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 11:13:05 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/12 11:13:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_arrayini(t_array *array)
{
	array->data = MAL(void*, 16);
	if (array->data != NULL)
		ft_bzero(array->data, 16);
	array->length = 0;
	array->alloc_length = (array->data == NULL) ? 0 : 16;
}
