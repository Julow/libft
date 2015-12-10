/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nanoclock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:58:12 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

#ifdef __APPLE__
# include <mach/mach_time.h>
# include <mach/mach.h>
#else
# include <time.h>
#endif
#ifdef __APPLE__

uint64_t			ft_nanoclock(uint64_t start)
{
	static mach_timebase_info_data_t	timebase = {0, 0};

	if (timebase.denom == 0)
		mach_timebase_info(&timebase);
	return (mach_absolute_time() * timebase.numer / timebase.denom - start);
}

#else

uint64_t			ft_nanoclock(uint64_t start)
{
	struct timespec	spec;

	clock_gettime(CLOCK_MONOTONIC, &spec);
	return (spec.tv_sec * NANO_SEC + spec.tv_nsec - start);
}

#endif
