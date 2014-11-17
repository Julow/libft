/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:07:31 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:07:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array			*ft_arraynew(void)
{
	t_array			*array;

	array = MAL1(t_array);
	if (array != NULL)
	{
		array->data = MAL(void*, 0);
		array->length = 0;
		array->alloc_length = 0;
	}
	return (array);
}
