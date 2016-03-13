/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 18:02:48 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/13 22:35:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec3.h"
#include <math.h>

t_vec3			ft_vec3front(t_vec2 a)
{
	float const		cos_y = cosf(a.y);

	return ((t_vec3){cosf(a.x) * cos_y, sinf(a.y), sinf(a.x) * cos_y});
}
