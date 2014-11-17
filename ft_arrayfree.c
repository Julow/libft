/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:37:19 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:37:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Free unused memory
** =============
** Return FALSE(0) if the malloc fail, TRUE(1) otherwise
*/
t_bool			ft_arrayfree(t_array *array)
{
	void			**tmp;
	int				i;

	if (array->length >= array->alloc_length)
		return (TRUE);
	tmp = MAL(void*, array->length);
	if (tmp == NULL)
		return (FALSE);
	array->alloc_length = array->length;
	if (array->data != NULL)
	{
		i = -1;
		while (++i < array->length)
			tmp[i] = array->data[i];
		free(array->data);
	}
	array->data = tmp;
	return (TRUE);
}
