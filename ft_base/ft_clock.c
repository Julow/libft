/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 19:23:34 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"
#include <sys/time.h>

t_ulong			ft_clock(t_ulong start)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	return (tval.tv_sec * MICRO_SEC + tval.tv_usec - start);
}
