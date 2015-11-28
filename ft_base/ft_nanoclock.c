/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nanoclock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:58:12 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:57 by juloo            ###   ########.fr       */
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

t_ulong			ft_nanoclock(t_ulong start)
{
	static mach_timebase_info_data_t	timebase = {0, 0};

	if (timebase.denom == 0)
		mach_timebase_info(&timebase);
	return (mach_absolute_time() * timebase.numer / timebase.denom - start);
}

#else

t_ulong			ft_nanoclock(t_ulong start)
{
	struct timespec	spec;

	clock_gettime(CLOCK_MONOTONIC, &spec);
	return (spec.tv_sec * NANO_SEC + spec.tv_nsec - start);
}

#endif
