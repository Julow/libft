/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:07:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:51:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include <stdlib.h>

t_array			*ft_arraynew(void)
{
	t_array			*array;

	array = MAL1(t_array);
	if (array == NULL)
		return (NULL);
	ft_arrayini(array);
	return (array);
}
