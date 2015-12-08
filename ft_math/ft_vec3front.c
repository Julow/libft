/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 18:02:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 16:59:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"
#include <math.h>

t_vec3			ft_vec3front(t_vec2 a)
{
	float const		cos_y = cosf(a.y);

	return ((t_vec3){cosf(a.x) * cos_y, sinf(a.y), sinf(a.x) * cos_y});
}
