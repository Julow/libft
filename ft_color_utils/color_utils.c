/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:26:15 by juloo             #+#    #+#             */
/*   Updated: 2016/05/12 23:45:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"

t_vec3			color_24tof(uint32_t color)
{
	return (COLOR_24TOF(color));
}

t_vec4			color_32tof(uint32_t color)
{
	return (COLOR_32TOF(color));
}

uint32_t		color_fto24(t_vec3 color)
{
	return (COLOR_FTO24(color));
}

uint32_t		color_fto32(t_vec4 color)
{
	return (COLOR_FTO32(color));
}
