/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gbclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:46:24 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 15:46:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		gb_free_one(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

void			ft_gbclear(void)
{
	t_array			**gb;

	gb = ft_gbget();
	ft_arraykil(*gb, &gb_free_one);
	*gb = NULL;
}
