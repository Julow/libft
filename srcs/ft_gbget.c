/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gbget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:45:58 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 15:45:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array			**ft_gbget(void)
{
	static t_array	*gb = NULL;

	if (gb == NULL)
	{
		gb = (t_array*)malloc(sizeof(t_array));
		gb->data = (void**)malloc(0);
		gb->length = 0;
		gb->alloc_length = 0;
	}
	return (&gb);
}
