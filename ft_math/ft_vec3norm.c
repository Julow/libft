/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:12:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 16:59:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"
#include <math.h>

t_vec3			ft_vec3norm(t_vec3 v)
{
	float const		len = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	if (len == 0.f)
		return ((t_vec3){0.f, 0.f, 0.f});
	return ((t_vec3){v.x / len, v.y / len, v.z / len});
}
