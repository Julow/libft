/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gbmalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:46:10 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 15:46:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_gbmalloc(t_uint size)
{
	void			*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putstr_fd("Error: Not enough memory.\n", 2);
		ft_gbclear();
		exit(1);
	}
	ft_arrayadd(*(ft_gbget()), ptr);
	return (ptr);
}
