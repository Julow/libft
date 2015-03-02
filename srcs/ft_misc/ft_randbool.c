/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randbool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 12:43:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/02 12:43:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_bool			ft_randbool(double chance)
{
	double			r;

	r = rand();
	r /= RAND_MAX;
	if (r < chance)
		return (true);
	return (false);
}
