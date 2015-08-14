/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pairchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:16:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:57:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int				ft_pairchr(t_array *array, const char *key)
{
	int				i;
	t_pair			*tmp;

	i = -1;
	while (++i < array->length)
	{
		tmp = (t_pair*)(array->data[i]);
		if (ft_strequ(tmp->key->content, key))
			return (i);
	}
	return (-1);
}
