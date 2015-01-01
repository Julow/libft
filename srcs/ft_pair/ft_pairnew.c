/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pairnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:15:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/01 13:15:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_pair			*ft_pairnew(const char *key, void *value)
{
	t_pair			*pair;

	pair = MAL1(t_pair);
	if (pair == NULL)
		return (NULL);
	pair->key = ft_stringnew();
	ft_stringadd(pair->key, key);
	pair->value = value;
	return (pair);
}
