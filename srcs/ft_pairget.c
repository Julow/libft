/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pairget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:16:11 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/01 13:16:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pair			*ft_pairget(t_array *array, const char *key)
{
	int				i;
	t_pair			*tmp;

	i = -1;
	while (++i < array->length)
	{
		tmp = (t_pair*)(array->data[i]);
		if (ft_strequ(key, tmp->key->content))
			return (tmp);
	}
	return (NULL);
}
