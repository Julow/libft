/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:17:51 by juloo             #+#    #+#             */
/*   Updated: 2016/04/05 08:54:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTILS_H
# define COLOR_UTILS_H

# include "ft/libft.h"
# include "ft/math_vec3.h"
# include "ft/math_vec4.h"

/*
** ========================================================================== **
** Color utils
** -
** color_fto24		3 floats to 24 bits
** color_fto32		4 floats to 32 bits
** color_24tof		24 bits to 3 floats
** color_32tof		32 bits to 4 floats
** color_sto32		hex string to 32 bits
** -
** COLOR_24TOF(C+)	Macro version of color_24tof
** COLOR_32TOF(C+)	Macro version of color_32tof
** COLOR_FTO24(C+)	Macro version of color_fto24
** COLOR_FTO32(C+)	Macro version of color_fto32
** -
** COLOR24(R,G,B)	24 bits color constructor
** COLOR32(A,R,G,B)	32 bits color constructor
*/

# define COLOR_24TOF(C)	(VEC3(_32TOF_R(C), _32TOF_G(C), _32TOF_B(C)))
# define COLOR_32TOF(C)	(VEC4(_32TOF_R(C),_32TOF_G(C),_32TOF_B(C),_32TOF_A(C)))

# define COLOR_FTO24(C)	(_FTO32_R((C).x) | _FTO32_G((C).y) | _FTO32_B((C).z))
# define COLOR_FTO32(C)	(COLOR_FTO24(C) | _FTO32_A((C).w))

# define COLOR24(R,G,B)		(_COLOR32_R(R) | _COLOR32_G(G) | _COLOR32_B(B))
# define COLOR32(A,R,G,B)	(_COLOR32_A(A) | COLOR24(R, G, B))

uint32_t		color_fto24(t_vec3 color);
uint32_t		color_fto32(t_vec4 color);
t_vec3			color_24tof(uint32_t color);
t_vec4			color_32tof(uint32_t color);

uint32_t		color32_gamma(uint32_t color, float gamma);
t_vec3			colorf_gamma(t_vec3 color, float gamma);

/*
** Convert hex string to 32 bits color
** -
** #RRGGBB
** #AARRGGBB
** -
** '#' prefix is optionnal
** 'R', 'G', 'B', 'A' are hex digits
** Default alpha is 'FF'
** Ignore case
*/
bool			color_hex(t_sub str, uint32_t *dst);

/*
** Alpha blending
** Put 'src' on 'dst'
*/
uint32_t		color32_blend(uint32_t dst, uint32_t src);
void			colorf_blend(t_vec4 *color, t_vec4 const *src);

/*
** COLOR32_A(C)		Return the alpha channel
** COLOR32_R(C)		Return the r channel
** COLOR32_G(C)		Return the g channel
** COLOR32_B(C)		Return the b channel
*/

# define COLOR32_A(C)		(((C) & COLOR32_A_MASK) >> COLOR32_A_OFFSET)
# define COLOR32_R(C)		(((C) & COLOR32_R_MASK) >> COLOR32_R_OFFSET)
# define COLOR32_G(C)		(((C) & COLOR32_G_MASK) >> COLOR32_G_OFFSET)
# define COLOR32_B(C)		(((C) & COLOR32_B_MASK) >> COLOR32_B_OFFSET)

/*
** -
** COLOR32_*_MASK		channel mask for 32/24 bits colors
** COLOR32_*_OFFSET		channel offset for 32/24 bits colors
** COLORF_*_FACTOR		factor used to convert from float colors
*/

# define COLOR32_A_MASK		0xFF000000
# define COLOR32_R_MASK		0x00FF0000
# define COLOR32_G_MASK		0x0000FF00
# define COLOR32_B_MASK		0x000000FF

# define COLOR32_A_OFFSET	24
# define COLOR32_R_OFFSET	16
# define COLOR32_G_OFFSET	8
# define COLOR32_B_OFFSET	0

# define COLORF_A_FACTOR	(255.f * 255.f * 255.f * 255.f)
# define COLORF_R_FACTOR	(255.f * 255.f * 255.f)
# define COLORF_G_FACTOR	(255.f * 255.f)
# define COLORF_B_FACTOR	(255.f)

/*
** -
*/

# define _32TOF_A(C)	(((float)((C) & COLOR32_A_MASK)) / COLORF_A_FACTOR)
# define _32TOF_R(C)	(((float)((C) & COLOR32_R_MASK)) / COLORF_R_FACTOR)
# define _32TOF_G(C)	(((float)((C) & COLOR32_G_MASK)) / COLORF_G_FACTOR)
# define _32TOF_B(C)	(((float)((C) & COLOR32_B_MASK)) / COLORF_B_FACTOR)

# define _FTO32_R(X)	(((uint32_t)(X * COLORF_R_FACTOR)) & COLOR32_R_MASK)
# define _FTO32_G(Y)	(((uint32_t)(Y * COLORF_G_FACTOR)) & COLOR32_G_MASK)
# define _FTO32_B(Z)	(((uint32_t)(Z * COLORF_B_FACTOR)) & COLOR32_B_MASK)
# define _FTO32_A(W)	(((uint32_t)(W * COLORF_A_FACTOR)) & COLOR32_A_MASK)

# define _COLOR32_A(C)	(((C) & 0xFF) << COLOR32_A_OFFSET)
# define _COLOR32_R(C)	(((C) & 0xFF) << COLOR32_R_OFFSET)
# define _COLOR32_G(C)	(((C) & 0xFF) << COLOR32_G_OFFSET)
# define _COLOR32_B(C)	(((C) & 0xFF) << COLOR32_B_OFFSET)

#endif
