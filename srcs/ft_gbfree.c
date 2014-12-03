/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gbfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:46:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 15:46:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_gbfree(void *ptr)
{
	int				index;
	t_array			*gb;

	gb = *(ft_gbget());
	index = ft_arraychr(gb, ptr);
	if (index >= 0)
	{
		ft_arrayrem(gb, index);
		if (ptr != NULL)
			free(ptr);
	}
}
