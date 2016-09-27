/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 19:23:34 by juloo             #+#    #+#             */
/*   Updated: 2016/09/27 17:03:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"
#include <sys/time.h>

uint64_t			ft_clock(uint64_t start)
{
	struct timeval	tval;
	uint64_t		t;

	gettimeofday(&tval, NULL);
	t = TIMEVAL_TO_USEC(tval);
	return ((t > start) ? t - start : 0);
}
