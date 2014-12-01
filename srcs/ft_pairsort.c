/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pairsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:17:31 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/01 13:17:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_pairsort(t_array *array)
{
	int				i;
	int				j;

	i = -1;
	while (++i < array->length)
	{
		j = i;
		while (++j < array->length)
		{
			if (ft_strcmp(((t_pair*)array->data[i])->key->content,
				((t_pair*)array->data[j])->key->content) > 0)
				ft_arrayswap(array, i, j);
		}
	}
}
