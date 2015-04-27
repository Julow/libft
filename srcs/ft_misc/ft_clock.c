/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 19:23:34 by juloo             #+#    #+#             */
/*   Updated: 2015/04/27 19:24:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

t_ulong			ft_clock(t_ulong start)
{
	struct timespec	tmp;

	clock_gettime(CLOCK_MONOTONIC, &tmp);
	return (tmp.tv_sec * FT_CPS + tmp.tv_nsec - start);
}
