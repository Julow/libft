/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pairrem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:17:17 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/01 13:17:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pair			*ft_pairrem(t_array *array, const char *key)
{
	int				i;
	t_pair			*tmp;

	i = -1;
	while (++i < array->length)
	{
		tmp = (t_pair*)(array->data[i]);
		if (ft_strequ(tmp->key->content, key))
		{
			ft_arrayrem(array, i);
			return (tmp);
		}
	}
	return (NULL);
}
