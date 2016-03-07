/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 12:41:54 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/05 16:27:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"
#include <stdlib.h>

static int		r(void)
{
	static bool		init = false;

	if (!init)
		srand(ft_clock(0));
	return (rand());
}

int32_t			ft_rand(int32_t min, int32_t max)
{
	return (r() % (max - min + 1) + min);
}

float			ft_randf(void)
{
	return (((float)r()) / (float)RAND_MAX);
}

bool			ft_randbool(float chance)
{
	if (chance >= 1.f || (chance > 0.f && r() < (int32_t)(RAND_MAX * chance)))
		return (true);
	return (false);
}
