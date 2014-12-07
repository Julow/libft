/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/ft_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 15:39:27 by juloo             #+#    #+#             */
/*   Updated: 2014/12/07 15:39:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_malloc(t_uint size)
{
	void			*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
	{
		ft_putstr_fd("Memory error: Not enough memory\n", 2);
		exit(1);
	}
	return (tmp);
}
