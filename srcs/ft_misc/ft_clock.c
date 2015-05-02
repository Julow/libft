/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 19:23:34 by juloo             #+#    #+#             */
/*   Updated: 2015/05/02 13:03:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <time.h>

#ifdef __MACH__
# define GET_CLOCK(tmp)		tmp = (struct timespec){0, clock() * 1000}
#else
# define GET_CLOCK(tmp)		clock_gettime(CLOCK_MONOTONIC, &tmp)
#endif

t_ulong			ft_clock(t_ulong start)
{
	struct timespec	tmp;

	GET_CLOCK(tmp);
	return (tmp.tv_sec * FT_CPS + tmp.tv_nsec - start);
}
